template <class T>
RedBlackTree<T>::RedBlackTree() : BinarySearchTree<T>() {}

template <class T>
bool RedBlackTree<T>::add(const T& element)
{
	BinarySearchTree<T>::add(element);
	RedBlackNode * node = this->castToRedBlackNode(this->nLastAdded);
	node->color = Color::RED;
	this->balanceAfterAdd(node);
	return true;
}

template <class T>
bool RedBlackTree<T>::remove(const T& element)
{
	RedBlackNode * toDelete = this->castToRedBlackNode(this->findNode(this->nRoot, element));
	if (!toDelete)
	{
		return false;
	}

	/*
	 * If it has two children, transform it into a case where it has a single child.
	 */
	if (toDelete->nLeft && toDelete->nRight)
	{
		RedBlackNode * maxNode = this->castToRedBlackNode(this->rightmostInSubtree(toDelete));
		toDelete->tElement = maxNode->tElement;
		toDelete = maxNode;
	}

	/*
	 * Reference for toDelete's child. If it has no children, it will be a ghost node.
	 */
	RedBlackNode * child;
	if (!toDelete->nLeft && !toDelete->nRight)
	{
		child = this->castToRedBlackNode(this->createNode(element));
		child->isGhost = true;
		child->color = Color::BLACK;
		child->nParent = toDelete;
		toDelete->nLeft = child;
	}
	else
	{
		child = (toDelete->nLeft) ?
				this->castToRedBlackNode(toDelete->nLeft) :
				this->castToRedBlackNode(toDelete->nRight);
	}

	remove(toDelete);

	if (this->isRed(child))
	{
		child->color = Color::BLACK;
	}
	else if (this->isBlack(toDelete))
	{
		this->balanceAfterRemove(child);
	}

	if (child->isGhost)
	{
		this->replaceDescendant(child, nullptr);
		child->nLeft = nullptr;
		child->nRight = nullptr;
		delete child;
	}

	toDelete->nLeft = nullptr;
	toDelete->nRight = nullptr;
	delete toDelete;

	this->numElements--;
	return true;
}

/*
 * External users of this class should not be allowed to perform rotations.
 * This method always returns false since no modification can ever be done.
 */
template <class T>
bool RedBlackTree<T>::rotateLeft(BinaryTreeNode<T> * node)
{
	(void)node;
	return false;
}

/*
 * External users of this class should not be allowed to perform rotations.
 * This method always returns false since no modification can ever be done.
 */
template <class T>
bool RedBlackTree<T>::rotateRight(BinaryTreeNode<T> * node)
{
	(void)node;
	return false;
}

template <class T>
Color RedBlackTree<T>::getColor(BinaryTreeNode<T> * node)
{
	return this->castToRedBlackNode(node)->color;
}

template <class T>
RedBlackTree<T>::RedBlackNode::RedBlackNode(const T& tElement) : 
BinaryTree<T>::Node::Node(tElement), color(Color::NONE) { isGhost = false; }

template <class T>
typename BinaryTree<T>::Node * RedBlackTree<T>::createNode(const T& val)
{
	return new typename RedBlackTree<T>::RedBlackNode(val);
}

template <class T>
typename RedBlackTree<T>::RedBlackNode * RedBlackTree<T>::castToRedBlackNode(BinaryTreeNode<T> * node)
{
	typename RedBlackTree<T>::RedBlackNode
		* original = dynamic_cast<typename RedBlackTree<T>::RedBlackNode *>(node);
		return original;
}

template <class T>
void RedBlackTree<T>::balanceAfterAdd(typename RedBlackTree<T>::RedBlackNode * node)
{
	/*
	 * Case 1: node has no parent.
	 */
	if (!node->nParent)
	{
		node->color = Color::BLACK;
		return;
	}

	typename RedBlackTree<T>::RedBlackNode * parent = this->castToRedBlackNode(node->nParent);

	/*
	 * Case 2: parent is black.
	 */
	if (this->isBlack(parent))
	{
		return;
	}

	typename RedBlackTree<T>::RedBlackNode 
		* grandparent = this->getGrandparent(node),
		* uncle = this->getUncle(node);

	/*
	 * Case 3: uncle is red.
	 */
	if (this->isRed(uncle))
	{
		parent->color = Color::BLACK;
		uncle->color = Color::BLACK;
		grandparent->color = Color::RED;
		this->balanceAfterAdd(grandparent);
		return;
	}

	/*
	 * Case 4: node and parent are "crossed".
	 */
	if (this->isLeftChild(parent) != this->isLeftChild(node))
	{
		if (this->isLeftChild(node))
		{
			BinarySearchTree<T>::rotateRight(parent);
		}
		else
		{
			BinarySearchTree<T>::rotateLeft(parent);
		}
		typename RedBlackTree<T>::RedBlackNode * auxiliary = node;
		node = parent;
		parent = auxiliary;
	}

	/*
	 * Case 5
	 */
	parent->color = Color::BLACK;
	grandparent->color = Color::RED;
	if (this->isLeftChild(parent))
	{
		BinarySearchTree<T>::rotateRight(grandparent);
	}
	else
	{
		BinarySearchTree<T>::rotateLeft(grandparent);
	}
}

template <class T>
void RedBlackTree<T>::balanceAfterRemove(typename RedBlackTree<T>::RedBlackNode * node)
{
	/*
	 * Case 1: node is the new root.
	 */
	if (!node->nParent)
	{
		this->nRoot = node;
		return;
	}

	typename RedBlackTree<T>::RedBlackNode 
		* parent = this->castToRedBlackNode(node->nParent),
		* sibling = this->getSibling(node);

	/*
	 * Case 2: sibling is red.
	 */
	if (this->isRed(sibling))
	{
		parent->color = Color::RED;
		sibling->color = Color::BLACK;
		if (this->isLeftChild(node))
		{
			BinarySearchTree<T>::rotateLeft(parent);
		}
		else
		{
			BinarySearchTree<T>::rotateRight(parent);	
		}
		sibling = this->getSibling(node);
	}

	/*
	 * Case 3: parent, sibling, and sibling's children are black.
	 */
	if (this->isBlack(parent) 
		&& this->isBlack(sibling)
		&& this->isBlack(sibling->nLeft)
		&& this->isBlack(sibling->nRight))
	{
		sibling->color = Color::RED;
		this->balanceAfterRemove(parent);
		return;
	}

	/*
	 * Case 4: parent is red, sibling and sibling's children are black.
	 */
	if (this->isRed(parent) 
		&& this->isBlack(sibling)
		&& this->isBlack(sibling->nLeft)
		&& this->isBlack(sibling->nRight))
	{
		parent->color = Color::BLACK;
		sibling->color = Color::RED;
		return;
	}

	/*
	 * Case 5a: node is left child, sibling is black, sibling's children are red and black.
	 */
	if (this->isLeftChild(node) 
		&& this->isBlack(sibling)
		&& this->isRed(sibling->nLeft)
		&& this->isBlack(sibling->nRight))
	{
		sibling->color = Color::RED;
		(this->castToRedBlackNode(sibling->nLeft))->color = Color::BLACK;
		BinarySearchTree<T>::rotateRight(sibling);	
	}
	/*
	 * Case 5b: node is right child, sibling is black, sibling's children are black and red.
	 */
	else if (!(this->isLeftChild(node)) 
		&& this->isBlack(sibling)
		&& this->isBlack(sibling->nLeft)
		&& this->isRed(sibling->nRight))
	{
		sibling->color = Color::RED;
		(this->castToRedBlackNode(sibling->nRight))->color = Color::BLACK;
		BinarySearchTree<T>::rotateLeft(sibling);	
	}

	sibling = getSibling(node);
	sibling->color = parent->color;
	parent->color = Color::BLACK;

	/*
	 * Case 6a: node is left child, sibling was black, sibling's right child is red.
	 */
	if (this->isLeftChild(node))
	{
		(this->castToRedBlackNode(sibling->nRight))->color = Color::BLACK;
		BinarySearchTree<T>::rotateLeft(parent);	
	}
	/*
	 * Case 6b: node is right child, sibling was black, sibling's left child is red.
	 */
	else
	{
		(this->castToRedBlackNode(sibling->nLeft))->color = Color::BLACK;
		BinarySearchTree<T>::rotateRight(parent);		
	}
}

template <class T>
void RedBlackTree<T>::remove(typename BinaryTree<T>::Node * node)
{
	if (node->nLeft)
	{
		(node->nLeft)->nParent = node->nParent;
		this->replaceDescendant(node, node->nLeft);
	}
	else
	{
		(node->nRight)->nParent = node->nParent;
		this->replaceDescendant(node, node->nRight);
	}
}

template <class T>
void RedBlackTree<T>::replaceDescendant(typename BinaryTree<T>::Node * node1, typename BinaryTree<T>::Node * node2)
{
	if (node1->nParent)
	{
		if (this->isLeftChild(node1))
		{
			(node1->nParent)->nLeft = node2;
		}
		else
		{
			(node1->nParent)->nRight = node2;
		}
	}
	else
	{
		this->nRoot = node2;
	}
}

template <class T>
bool RedBlackTree<T>::isRed(typename BinaryTree<T>::Node * node)
{
	return node && (this->getColor(node) == Color::RED);
}

template <class T>
bool RedBlackTree<T>::isBlack(typename BinaryTree<T>::Node * node)
{
	return node && (this->getColor(node) == Color::BLACK);
}

template <class T>
bool RedBlackTree<T>::isLeftChild(typename BinaryTree<T>::Node * node)
{
	return (node->nParent)->nLeft == node;
}

template <class T>
typename RedBlackTree<T>::RedBlackNode * RedBlackTree<T>::getSibling(typename BinaryTree<T>::Node * node)
{
	if (this->isLeftChild(node))
	{
		return this->castToRedBlackNode((node->nParent)->nRight);
	}
	else
	{
		return this->castToRedBlackNode((node->nParent)->nLeft);
	}
}

template <class T>
typename RedBlackTree<T>::RedBlackNode * RedBlackTree<T>::getUncle(typename BinaryTree<T>::Node * node)
{
	if (((node->nParent)->nParent)->nLeft == node->nParent)
	{
		return this->castToRedBlackNode(((node->nParent)->nParent)->nRight);
	}
	else
	{
		return this->castToRedBlackNode(((node->nParent)->nParent)->nLeft);
	}
}

template <class T>
typename RedBlackTree<T>::RedBlackNode * RedBlackTree<T>::getGrandparent(typename BinaryTree<T>::Node * node)
{
	return this->castToRedBlackNode((node->nParent)->nParent);
}