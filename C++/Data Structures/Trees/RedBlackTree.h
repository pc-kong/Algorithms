#include "BinarySearchTree.h"

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

enum class Color {RED, BLACK};

template <class T> 
class RedBlackTree: public BinarySearchTree<T>
{
	public:
		RedBlackTree();
		template <typename Iterable> RedBlackTree(const Iterable&);
		bool add(const T&) override;
		bool remove(const T&) override;
		bool rotateLeft(BinaryTreeNode<T> *) override;
		bool rotateRight(BinaryTreeNode<T> *) override;
		Color getColor(BinaryTreeNode<T> *);
	protected:
		class RedBlackNode: public BinarySearchTree<T>::Node
		{
			public:
				Color color;
				RedBlackNode(const T&);
				bool operator ==(const typename BinaryTree<T>::Node&) override;
		};
		virtual RedBlackNode * createNode(const T&) override;
	private:
		void rebalanceAdd(RedBlackNode *);
		void rebalanceRemove(RedBlackNode *);
		void remove(RedBlackNode *);
		void replaceDescendant(RedBlackNode *);
		bool isBlack(RedBlackNode *);
		bool isRed(RedBlackNode *);
		bool isLeftChild(RedBlackNode *);
		RedBlackNode * getSibling(RedBlackNode *);
		RedBlackNode * getUncle(RedBlackNode *);
		RedBlackNode * getGrandparent(RedBlackNode *);
};

#include "RedBlackTree.hxx"

#endif