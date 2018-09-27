#include "BinarySearchTree.h"

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

/**
 * The different values a RedBlackNode's color can have.
 */
enum class Color {RED, BLACK, NONE};

/**
 * Class representing a Red-Black Tree.
 * @tparam T any type that is accepted by BinarySearchTree.
 */
template <class T> 
class RedBlackTree: public BinarySearchTree<T>
{

	public:

		/**
		 * Constructs an empty Red-Black Tree.
		 */
		RedBlackTree();

		/**
		 * Gets the color of the given node.
		 * @param a node.
		 * @return a Color.
		 */
		Color getColor(BinaryTreeNode<T> * node);

		bool add(const T&) override;
		bool remove(const T&) override;
		bool rotateLeft(BinaryTreeNode<T> *) override;
		bool rotateRight(BinaryTreeNode<T> *) override;

	protected:

		/**
		 * A class identical to BinarySearchTree::Node but with a Color property.
		 */
		class RedBlackNode: public BinarySearchTree<T>::Node
		{

			public:

				/**
				 * Determines if this node is a ghost node, used in Red-Black tree algorithms.
				 */
				bool isGhost;

				/**
				 * This node's color.
				 */
				Color color;

				/**
				 * Constructs a new node containing the given element.
				 * @param element the contained element.
				 */
				RedBlackNode(const T& element);

		};

		/**
		 * Casts a generic BinaryTreeNode to RedBlackTree::RedBlackNode.
		 * @return a RedBlackTree::RedBlackNode.
		 */
		virtual RedBlackNode * castToRedBlackNode(BinaryTreeNode<T> * node);

		virtual typename BinaryTree<T>::Node * createNode(const T&) override;

	private:

		/**
		 * This is rebalancing algorithm performed after an addition to a Red-Black Tree.
		 * @param node the node to start the algorithm with.
		 */
		void balanceAfterAdd(RedBlackNode * node);

		/**
		 * This is rebalancing algorithm performed after a removal from a Red-Black Tree.
		 * @param node the node to start the algorithm with.
		 */
		void balanceAfterRemove(RedBlackNode * node);

		/**
		 * Deletes a node with exactly one child.
		 * @param node a node.
		 */
		void remove(typename BinaryTree<T>::Node * node);

		/**
		 * Sets the first node's parent's child to the second node. If the first node has no parent, then the second
		 * node is the new root of this tree.
		 * @param node1 a node.
		 * @param node2 another node.
		 */
		void replaceDescendant(typename BinaryTree<T>::Node * node1, typename BinaryTree<T>::Node * node2);

		/**
		 * Determines if the given node is red.
		 * @param node a node.
		 * @return true if the given node is red.
		 */
		bool isRed(typename BinaryTree<T>::Node * node);

		/**
		 * Determines if the given node is black.
		 * @param node a node.
		 * @return true if the given node is black.
		 */
		bool isBlack(typename BinaryTree<T>::Node * node);

		/**
		 * Determines if the given node is a left child.
		 * @param node a node.
		 * @return true if the given node is a left child.
		 */
		bool isLeftChild(typename BinaryTree<T>::Node * node);

		/**
		 * Returns the given node's sibling.
		 * @param node a node.
		 * @return the given node's sibling.
		 */
		RedBlackNode * getSibling(typename BinaryTree<T>::Node * node);

		/**
		 * Returns the given node's uncle.
		 * @param node a node.
		 * @return the given node's uncle.
		 */
		RedBlackNode * getUncle(typename BinaryTree<T>::Node * node);

		/**
		 * Returns the given node's grandparent.
		 * @param node a node.
		 * @return the given node's grandparent.
		 */
		RedBlackNode * getGrandparent(typename BinaryTree<T>::Node * node);

};

#include "RedBlackTree.hxx"

#endif