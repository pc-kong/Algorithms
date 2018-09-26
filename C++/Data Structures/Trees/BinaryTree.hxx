template <class T> 
BinaryTree<T>::BinaryTree() : 
nRoot(nullptr), nLastAdded(nullptr), numElements(0) {}

template <class T> 
BinaryTree<T>::~BinaryTree() 
{ 
	delete this->nRoot; 
}

template <class T>
bool BinaryTree<T>::contains(const T& element) 
{
	return findNode(nRoot, element);
}

template <class T>
bool BinaryTree<T>::operator ==(const BinaryTree& other) 
{
	if (!this->nRoot && !other.nRoot)
	{
		return true;
	}		

	if (this->nRoot && other.nRoot)
	{
		return this->nRoot == other.nRoot;
	}

	return false;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::root() {
	return nRoot;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::find(const T& element) 
{
	return findNode(nRoot, element);
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::lastAdded() {
	return nLastAdded;
}

template <class T>
int BinaryTree<T>::height() 
{
	return (!nRoot) ? -1 : depth(nRoot);
}

template <class T>
bool BinaryTree<T>::empty() 
{
	return numElements == 0;
}

template <class T>
int BinaryTree<T>::size() 
{
	return numElements;
}

template <class T>
BinaryTree<T>::Node::Node(const T& tElement) : 
tElement(tElement), nParent(nullptr), nLeft(nullptr) , nRight(nullptr) {}

template <class T>
BinaryTree<T>::Node::~Node() 
{
	if (this->nLeft)
	{
		delete this->nLeft;
	}
	if (this->nRight)
	{
		delete this->nRight;
	}
}

template <class T>
const T& BinaryTree<T>::Node::element() const
{
	return tElement;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::Node::parent() const
{
	return nParent;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::Node::left() const
{
	return nLeft;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::Node::right() const
{
	return nRight;
}

template <class T>
bool BinaryTree<T>::Node::operator ==(const Node& other)
{
	// We can't use != because we've only asserted the existence of T's == operator.
	if (!(this->tElement == other.tElement))
	{
		return false;
	}

	bool leftSubtreesEqual = false, rightSubtreesEqual = false;

	if (this->nLeft && other.nLeft)
	{
		leftSubtreesEqual = this->nLeft == other.nLeft;
	} 
	else if (!this->nLeft && !other.nLeft)
	{
		leftSubtreesEqual = true;
	}

	if (this->nRight && other.nRight)
	{
		rightSubtreesEqual = this->nRight == other.nRight;
	} 
	else if (!this->nRight && !other.nRight)
	{
		rightSubtreesEqual = true;
	}

	return leftSubtreesEqual && rightSubtreesEqual;
}

template <class T>
typename BinaryTree<T>::Node * BinaryTree<T>::createNode(const T& val) 
{
	return new typename BinaryTree<T>::Node(val);
}

template <class T>
typename BinaryTree<T>::Node * BinaryTree<T>::findNode(Node * node, const T& val) 
{
	if (!node)
	{
		return nullptr;
	}

	if (node->tElement == val)
	{
		return node;
	}

	Node * searchLeft = findNode(node->nLeft, val);
	Node * searchRight = findNode(node->nRight, val);
	if (!searchLeft && !searchRight)
	{
		return nullptr;
	}

	return (searchLeft) ? searchLeft : searchRight;
}

template <class T>
int BinaryTree<T>::depth(Node * node) 
{
	if (!node->nLeft && !node->nRight)
	{
		return 0;
	}
	else if (node->nLeft && node->nRight)
	{
		int leftSubtreeDepth = 1 + depth(node->nLeft);
		int rightSubtreeDepth = 1 + depth(node->nRight);
		return (leftSubtreeDepth > rightSubtreeDepth) ?  leftSubtreeDepth : rightSubtreeDepth;
	}
	else
	{
		return (node->nLeft) ? 1 + depth(node->nLeft) : 1 + depth(node->nRight);
	}
}