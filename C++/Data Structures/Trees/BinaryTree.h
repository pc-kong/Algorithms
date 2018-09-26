#include "BinaryTreeNode.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

/* 
 * It's easier to not add the const modifier to root(), find(), and lastAdded()
 * and trusting the user not to break the semantics of the tree.
 * Adding it causes problems with public methods that receive a BinaryTreeNode
 * and must modify it.
 * Pointers are used instead of references to make use of nullptr. A user must 
 * first check if the result returned by root() or parent() is nullptr before
 * attempting to use it.
 */

template <class T> 
class BinaryTree
{
	public:		
		BinaryTree();
		virtual ~BinaryTree();
		virtual bool add(const T&) = 0;
		virtual bool remove(const T&) = 0;
		virtual bool contains(const T&);
		bool operator ==(const BinaryTree<T>&);
		BinaryTreeNode<T> * root();				// TODO: Throw exception if empty
		BinaryTreeNode<T> * find(const T&);		// TODO: Throw exception if not found 
		BinaryTreeNode<T> * lastAdded();		// TODO: Throw exception if not found 
		int height();
		bool empty();
		int size();

	protected:
		class Node: public BinaryTreeNode<T>
		{
			public:
				T tElement;
				Node * nParent, * nLeft, * nRight;
				Node(const T&);
				virtual ~Node();
				const T& element() const override;
				BinaryTreeNode<T> * parent() const override;
				BinaryTreeNode<T> * left() const override;
				BinaryTreeNode<T> * right() const override;
				virtual bool operator ==(const Node&);
		};	
		Node * nRoot, * nLastAdded;
		int numElements;
		virtual Node * createNode(const T&);
		virtual Node * findNode(Node *, const T&);
	private:
		static auto check(T& x, T& y) -> decltype(x == y);
		int depth(Node *);
};

#include "BinaryTree.hxx"

#endif