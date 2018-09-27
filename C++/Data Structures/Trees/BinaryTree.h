#include "BinaryTreeNode.h"

#ifndef BINARYTREE_H
#define BINARYTREE_H

/**
 * Abstract base class representing a Binary Tree.
 * @tparam T any type that implements the == operator.
 */
template <class T> 
class BinaryTree
{

	public:

		/**
		 * Constructs an empty tree. All this does is initialize variables for internal use.
		 */
		BinaryTree();

		/**
		 * Destructor that calls delete on the root node.
		 */
		virtual ~BinaryTree();

		/**
		 * Adds an element to this tree.
		 * @param element the element to add.
		 * @return true if this tree was modified.
		 */
		virtual bool add(const T& element) = 0;

		/**
		 * Removes an element from this tree.
		 * @param element the element to remove.
		 * @return true if this tree was modified.
		 */
		virtual bool remove(const T& element) = 0;

		/**
		 * Checks if the given element is in this tree.
		 * @param element an element to check for.
		 * @return true if this tree contains the element.
		 */
		virtual bool contains(const T& element);

		/**
		 * Checks if this tree's root is equal to another tree's root.
		 * @param other the other tree to compare this one to.
		 * @return true if the roots are equal.
		 */
		bool operator ==(const BinaryTree<T>& other);
		BinaryTreeNode<T> * root();
		BinaryTreeNode<T> * find(const T&);
		BinaryTreeNode<T> * lastAdded();
		int height();
		bool empty();
		int size();

	protected:

		/**
		 * Usable implementation of the BinaryTreeNode interface.
		 */
		class Node: public BinaryTreeNode<T>
		{

			public:

				/**
				 * This node's contained element.
				 */
				T tElement;

				/**
				 * This node's parent.
				 */
				Node * nParent;

				/**
             	 * This node's left child.
             	 */
				Node * nLeft;

				/**
				 * This node's right child.
				 */
				Node * nRight;

				/**
				 * Constructs a node that contains the given element.
				 * @param element an element to contain.
				 */
				Node(const T& element);

				/**
				 * This destructor calls delete on the child nodes.
				 */
				virtual ~Node();

				/**
				 * Two nodes are equal if they're null, or if their elements are equal and their left and right
				 * subtrees are equal.
				 * @param other node to compare this one to.
				 * @return true if this node is equal to the other.
				 */
				virtual bool operator ==(const Node& other);

				const T& element() const override;
				BinaryTreeNode<T> * parent() const override;
				BinaryTreeNode<T> * left() const override;
				BinaryTreeNode<T> * right() const override;

		};

		/**
		 * The root of this tree.
		 */
		Node * nRoot;

		/**
		 * The node of this tree that was last added.
		 */
		Node * nLastAdded;

		/**
		 * The size of this tree.
		 */
		int numElements;

		/**
		 * Derived classes should override and use this method for creating new nodes.
		 * @param element the contained element.
		 * @return a new node with memory allocated with the new operator.
		 */
		virtual Node * createNode(const T& element);

		/**
		 * Finds an element in this tree and returns its containing node.
		 * @param node the node to start the search from.
		 * @param element the element to search for.
		 * @return the node containing the given element.
		 */
		virtual Node * findNode(Node * node, const T& element);

	private:

		/**
		 * This static method is used to generate a compile-time error if T does not override the == operator.
		 */
		static auto check(T& x, T& y) -> decltype(x == y);

		/**
		 * Computes the depth of a node (distance from the node to the root).
		 * A null node has depth -1 and childless node has depth 0.
		 * @param node get the depth of this node.
		 * @return the depth of a node.
		 */
		int depth(Node * node);

};

#include "BinaryTree.hxx"

#endif