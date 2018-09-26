#include <iostream>

template <class T> 
BinarySearchTree<T>::BinarySearchTree() : BinaryTree<T>() {}

template <class T> 
template <typename Iterable> 
BinarySearchTree<T>::BinarySearchTree(const Iterable& it) : BinaryTree<T>()
{
	for (int i = 0; std::next(it.begin(), i) != it.end(); i++)
	{
		add(*std::next(it.begin(), i));
	}
}

template <class T>
bool BinarySearchTree<T>::add(const T& element)
{
	typename BinaryTree<T>::Node * node = this->createNode(element);
	if (this->nRoot)
	{
		this->add(this->nRoot, node);
	}
	else
	{
		this->nRoot = node;
	}
	this->nLastAdded = node;
	this->numElements++;
	return true;
}

template <class T>
bool BinarySearchTree<T>::remove(const T& element)
{
	typename BinaryTree<T>::Node * node = findNode(this->nRoot, element);
	if (node)
	{
		remove(node);
		this->numElements--;
		return true;
	} 
	return false;
}

template <class T>
bool BinarySearchTree<T>::rotateLeft(BinaryTreeNode<T> * node)
{
	typename BinaryTree<T>::Node 
		* original = dynamic_cast<typename BinaryTree<T>::Node *>(node),
		* auxiliary = original->nRight;
	if (!original->nRight)
	{
		return false;
	}

	if (auxiliary->nLeft)
	{
		(auxiliary->nLeft)->nParent = original;
	}
	original->nRight = auxiliary->nLeft;
	if (original->nParent)
	{
		replaceDescendant(original, auxiliary);
	}
	auxiliary->nLeft = original;
	auxiliary->nParent = original->nParent;
	original->nParent = auxiliary;
	if (this->nRoot == original)
	{
		this->nRoot = auxiliary;
	}

	return true;
}

template <class T>
bool BinarySearchTree<T>::rotateRight(BinaryTreeNode<T> * node)
{
	typename BinaryTree<T>::Node 
		* original = dynamic_cast<typename BinaryTree<T>::Node *>(node),
		* auxiliary = original->nLeft;
	if (!original->nLeft)
	{
		return false;
	}

	if (auxiliary->nRight)
	{
		(auxiliary->nRight)->nParent = original;
	}
	original->nLeft = auxiliary->nRight;
	if (original->nParent)
	{
		replaceDescendant(original, auxiliary);
	}
	auxiliary->nRight = original;
	auxiliary->nParent = original->nParent;
	original->nParent = auxiliary;
	if (this->nRoot == original)
	{
		this->nRoot = auxiliary;
	} 

	return true;
}

template <class T>
typename BinaryTree<T>::Node * BinarySearchTree<T>::findNode(typename BinaryTree<T>::Node * node, const T& element)
{
	if (!node)
	{
		return nullptr;
	}
	if (element == node->tElement)
	{
		return node;
	}
	return (element < node->tElement) ? findNode(node->nLeft, element) : findNode(node->nRight, element);
}

template <class T>
typename BinaryTree<T>::Node * BinarySearchTree<T>::rightmostInSubtree(typename BinaryTree<T>::Node * node)
{
	if (!node)
	{
		return nullptr;
	}
	return rightmostInSubtreeAux(node->nLeft);
}

template <class T>
void BinarySearchTree<T>::add(typename BinaryTree<T>::Node * node, typename BinaryTree<T>::Node * newNode)
{
	// We can't use <= because we've only asserted the existence of T's == and < operators.
	if (newNode->tElement < node->tElement || newNode->tElement == node->tElement)
	{
		if (node->nLeft)
		{
			this->add(node->nLeft, newNode);
		} 
		else
		{
			node->nLeft = newNode;
			newNode->nParent = node;
		}
	}
	else
	{
		if (node->nRight)
		{
			this->add(node->nRight, newNode);
		} 
		else
		{
			node->nRight = newNode;
			newNode->nParent = node;
		}
	}
}

template <class T>
void BinarySearchTree<T>::remove(typename BinaryTree<T>::Node * node)
{
	if (!node->nLeft && !node->nRight)
	{
		if (node->nParent)
		{
			replaceDescendant(node, nullptr);
		}
		else
		{
			this->nRoot = nullptr;
		}
		delete node;
	}
	else if (node->nLeft && node->nRight)
	{
		typename BinaryTree<T>::Node * maxNode = this->rightmostInSubtree(node);
		node->tElement = maxNode->tElement;
		remove(maxNode);
	}
	else
	{
		if (node->nLeft)
		{
			(node->nLeft)->nParent = node->nParent;
			if ((node->nLeft)->nParent)
			{
				replaceDescendant(node, node->nLeft);
			}
			else
			{
				this->nRoot = node->nLeft;
			}
		}
		else 
		{
			(node->nRight)->nParent = node->nParent;
			if ((node->nRight)->nParent)
			{
				replaceDescendant(node, node->nRight);
			}
			else
			{
				this->nRoot = node->nRight;
			}
		}
		/* 
		 * BinaryTree<T>::Node's destructor calls delete on its children, 
		 * so we set node's children to nullptr to avoid deleting inner nodes.
		 */
		node->nLeft = nullptr;
		node->nRight = nullptr;
		delete node;
	}
}

template <class T>
void BinarySearchTree<T>::replaceDescendant(typename BinaryTree<T>::Node * node1, typename BinaryTree<T>::Node * node2)
{
	if ((node1->nParent)->nLeft == node1)
	{
		(node1->nParent)->nLeft = node2;
	}
	else
	{
		(node1->nParent)->nRight = node2;
	}
}

template <class T>
typename BinaryTree<T>::Node * BinarySearchTree<T>::rightmostInSubtreeAux(typename BinaryTree<T>::Node * node)
{
	if (!node)
	{
		return nullptr;
	}
	if (!node->nRight)
	{
		return node;
	}
	return this->rightmostInSubtreeAux(node->nRight);
}