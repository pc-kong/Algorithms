#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

/**
 * Interface for interacting with Binary Tree nodes, without altering its components.
 * @tparam T any type in theory, although the class BinaryTree will restrict this to a type that
 * overloads the == operator.
 */
template<class T>
class BinaryTreeNode
{

	public:

		/**
		 * Returns the element contained in this node.
		 * @return this node's element.
		 */
		virtual const T& element() const = 0;

		/**
		 * Returns this node's parent.
		 * @return this node's parent.
		 */
		virtual BinaryTreeNode * parent() const = 0;

		/**
		 * Returns this node's left child.
		 * @return this node's left child.
		 */
		virtual BinaryTreeNode * left() const = 0;

		/**
		 * Returns this node's right child.
		 * @return this node's right child.
		 */
		virtual BinaryTreeNode * right() const = 0;

};

#endif
