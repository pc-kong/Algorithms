#include "BinaryTree.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T> 
class BinarySearchTree: public BinaryTree<T>
{
	public:
		BinarySearchTree();
		template <typename Iterable> BinarySearchTree(const Iterable&);
		bool add(const T&) override;
		bool remove(const T&) override;
		virtual bool rotateLeft(BinaryTreeNode<T> *);
		virtual bool rotateRight(BinaryTreeNode<T> *);
	protected:
		typename BinaryTree<T>::Node * findNode(typename BinaryTree<T>::Node *, const T&) override;
		typename BinaryTree<T>::Node * rightmostInSubtree(typename BinaryTree<T>::Node *);
	private:
		static auto check(T& x, T& y) -> decltype(x < y);
		void add(typename BinaryTree<T>::Node *, typename BinaryTree<T>::Node *);
		void remove(typename BinaryTree<T>::Node *);
		void replaceDescendant(typename BinaryTree<T>::Node *, typename BinaryTree<T>::Node *);
		typename BinaryTree<T>::Node * rightmostInSubtreeAux(typename BinaryTree<T>::Node *);
};

#include "BinarySearchTree.hxx"

#endif
