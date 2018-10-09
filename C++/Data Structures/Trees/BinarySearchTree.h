#include "BinaryTree.h"

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

/**
 * Class that represents a Binary Search Tree.
 * @tparam T any type that implements the < operator.
 */
template <class T> 
class BinarySearchTree: public BinaryTree<T>
{

	public:

		/**
		 * Constructs an empty Binary Search Tree.
		 */
		BinarySearchTree();

		/**
		 * Constructs a Binary Search Tree by adding the elements in the iterable structure one by one.
		 * @param it an iterable structure.
		 * @tparam Iterable an iterable type.
		 */
		template <typename Iterable> BinarySearchTree(const Iterable& it);

		/**
		 * Performs a left rotation on the given node.
		 * @param node the node to perform the rotation on.
		 * @return true if this tree was modified as a result of this operation.
		 */
		virtual bool rotateLeft(BinaryTreeNode<T> * node);

		/**
		 * Performs a right rotation on the given node.
		 * @param node the node to perform the rotation on.
		 * @return true if this tree was modified as a result of this operation.
		 */
		virtual bool rotateRight(BinaryTreeNode<T> * node);

		bool add(const T&) override;
		bool remove(const T&) override;

	protected:

		/**
		 * Get the maximum node in this subtree.
		 * @return the rightmost (maximum value) node in the subtree.
		 */
		typename BinaryTree<T>::Node * rightmostInSubtree(typename BinaryTree<T>::Node * node);

		typename BinaryTree<T>::Node * findNode(typename BinaryTree<T>::Node *, const T&) override;

	private:

		/**
		 * This static method is used to generate a compile-time error if T does not override the < operator.
		 */
		static auto check(T& x, T& y) -> decltype(x < y);

		/**
		 * Auxiliary method for adding a new node to this tree.
		 * @param node node that newNode will be compared to.
		 * @param newNode a brand-new node for this tree.
		 */
		void add(typename BinaryTree<T>::Node * node, typename BinaryTree<T>::Node * newNode);

		/**
		 * Auxiliary method for removing a node from this tree. Calls the delete operator on node.
		 * @param node the node to be removed.
		 */
		void remove(typename BinaryTree<T>::Node * node);

		/**
		 * Sets node2 as node1's parent's child.
		 * @param node1 a node.
		 * @param node2 another node.
		 */
		void replaceDescendant(typename BinaryTree<T>::Node * node1, typename BinaryTree<T>::Node * node2);

		/**
		 * Auxiliary method for finding the maximum value node in a subtree.
		 * @param node a node.
		 * @return the rightmost node.
		 */
		typename BinaryTree<T>::Node * rightmostInSubtreeAux(typename BinaryTree<T>::Node * node);

};

#include "BinarySearchTree.hxx"

#endif
