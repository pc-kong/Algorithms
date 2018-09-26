#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

template<class T> 
class BinaryTreeNode
{
	public:
		virtual const T& element() const = 0;
		virtual BinaryTreeNode * parent() const = 0;
		virtual BinaryTreeNode * left() const = 0;
		virtual BinaryTreeNode * right() const = 0;
};

#endif
