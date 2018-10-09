#include <iostream>
#include <string>

#include "SplayTree.h"

using namespace std;

/** Constructor for inner class SplayTree::Node */
SplayTree::Node::Node(int data, SplayTree::Node* left, 
	                     SplayTree::Node* right, SplayTree::Node* parent)
{
	this->data = data;
	this->left = left;
	this->right = right;
	this->parent = parent;
}

/** Constructor for inner class SplayTree::Node */
SplayTree::Node::Node(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

/** Constructor for inner class SplayTree*/
SplayTree::SplayTree()
{
	this->root = NULL;
	this->number_of_elements = 0;
}


/** 
	* Function that verifies if the tree is empty.
	* @return True if the tree is empty, False otherwise.
*/
bool SplayTree::is_empty()
{
	return number_of_elements == 0;
}

/** 
	* Function that return the number of elements in the tree.
	* @return number of elements. This is greater or equal to zero.
*/
int SplayTree::size()
{
	return number_of_elements;
}

/**
	* Access to the data of the root.
	* @return data of the root.
*/
int SplayTree::get_root_data()
{
	return root->data;
}

/**
	* Inserts an element to the tree.
	* First, inserts the node as a BST would do.
	* Then, applies splay operation on the new node, this will take node
	* up to the root.
	* @param data the element of the node that will be added.
*/
void SplayTree::insert(int data)
{	
	Node* element = new Node(data);
	if (root == NULL)
		root = element;
	else
	{
		insert_private(element, root);
		splay(element);
	}
	number_of_elements += 1;

}


/**
	* Private auxiliar function for inserting a node.
	* This is the same algorithm as BST.
	* @param e the Node that will be added.
	* @param parent The current node where we start searching.
*/
void SplayTree::insert_private(Node* e, Node* parent)
{	
	if (e->data < parent->data)
	{
		if (parent->left == NULL)
		{
			parent->left = e;
			e->parent = parent;
			return;
		}
		else
			insert_private(e, parent->left);
	}
	else 
	{
		if (parent->right == NULL)
		{
			parent->right = e;
			e->parent = parent;
			return;
		}
		else 
			insert_private(e, parent->right);
	}
}

/**
	* Prints the preorder traversal of the tree.
*/
void SplayTree::to_string()
{
	cout << "\tPre-order: [" + pre_order(root) + "]" << endl;
}

/**
	* Recursion implementation of preorder traversal.
	* Preorder traversal goes through left children, then current node,
	* finally right children.
	* @param ptr Node where we start the traversal.
	* @return string representation of the tree.
*/
string SplayTree::pre_order(Node* ptr)
{
	std::string currentValue;
	if (ptr == NULL)
		return currentValue;
	
	currentValue = std::to_string(ptr->data);
	string left  = pre_order(ptr->left);
	string right = pre_order(ptr->right);

	if (left.empty() && right.empty())
		return currentValue;
	
	if (!left.empty() && !right.empty())
		return currentValue + ", " + left + ", " + right;

	if (left.empty())
		return currentValue + ", " + right;
	return currentValue + ", " + left;
}

/**
	* Function that computes a right rotation over a node.
	* @param ptr Node where the rotation is going to be executed.
*/
void SplayTree::zig(Node* ptr)
{
	Node* tmp_node = ptr->right;
	int aux_data = ptr->data;
	
	if (ptr->left != NULL)
	{
		ptr->right = ptr->left;
		ptr->data = ptr->left->data;
		
		ptr->left = ptr->right->left;
		if (ptr->left != NULL)
			ptr->left->parent = ptr;
		
		ptr->right->left = ptr->right->right;
		
		ptr->right->right = tmp_node;
		if (ptr->right->right != NULL)
			ptr->right->right->parent = ptr->right;
		
		ptr->right->data = aux_data;
	}
}

/**
	* Function that computes a left rotation.
	* @param ptr Node where the rotation is going to be executed.
*/
void SplayTree::zag(Node* ptr)
{
	Node* tmp_node = ptr->left;
	int aux_data = ptr->data;
	
	if (ptr->right != NULL)
	{
		ptr->left = ptr->right;
		ptr->data = ptr->right->data;
		
		ptr->right = ptr->left->right;
		if (ptr->right != NULL)
			ptr->right->parent = ptr;

		ptr->left->right = ptr->left->left;
		
		ptr->left->left = tmp_node;
		if (ptr->left->left != NULL)
			ptr->left->left->parent = ptr->left;

		ptr->left->data = aux_data;
	}
}

/**
	* The function looks for the given key in the tree.
	* The search must start from the root so we can be sure that the 
	* key is(n't) in the tree.
	* In Splay Trees, search function always brings a node up to the root,
	* even if the given key is not in the tree.
	* @param key The key that will be compared against the node data.
	* @return Node that contains the given key, or a closer one.
*/
SplayTree::Node* SplayTree::search(int key)
{
	Node* node = search_private(key, root, root);
	if (node != NULL)
		splay(node);

	return node;
}

/**
	* Recursive auxiliar function for searching a key in the tree.
	* @param ptr Node that the function takes as root at the given recirsive call.
	* @param closer Node that keeps a reference to the last node that we have seen;
				  This node reference is for returning an element when the key is not in the tree.
*/
SplayTree::Node* SplayTree::search_private(int key, Node* ptr, Node* closer)
{
	if (ptr == NULL)
		return closer;
	
	if (ptr->data == key)
		return ptr;

	if (key < ptr->data)
		return search_private(key, ptr->left, ptr);
	return search_private(key, ptr->right, ptr);
}

/**
	* Recursive function that computes the splay of a node over a tree.
	* Splay is a function that takes a node reference and applying zig or zag
	* moves the node to the root.
	* @param ptr Node that will be splayed.
*/
void SplayTree::splay(Node* ptr)
{
	if (ptr == root)
		return;

	Node* parent = ptr->parent;
	if (parent == root)
	{
		if (ptr == parent->left)
			zig(parent);
		else
			zag(parent);
		ptr = parent;
		return;
	}

	Node* grandparent = parent->parent;
	if (ptr == parent->left && parent == grandparent->left)
	{
		zig(grandparent);
		zig(grandparent);
	}
	else if (ptr == parent->left && parent == grandparent->right)
	{
		zig(parent);
		zag(grandparent);
	}
	else if (ptr == parent->right && parent == grandparent->left)
	{
		zag(parent);
		zig(grandparent);
	}
	else if (ptr == parent->right && parent == grandparent->right)
	{
		zag(grandparent);
		zag(grandparent);
	}
	
	ptr = grandparent;
	splay(ptr);
}

/**
	* Function that removes a node of the tree.
	* First, it looks for the node containing data, then 
	* applies two splays, where at the end, the desired node will be on the root.
	* Finally just remove the root, verifying the cases for subtrees.
	* @param data that we are looking in the tree.
*/
void SplayTree::remove(int data)
{

	Node* node = search_private(data, root, root);
	if (node == NULL)
		return;
	
	/* If the element is in the tree, then search_private returns the element,
	   otherwise returns a near node to the data that we are looking for.
	   Then we have to verify that node has the same value data
	   before deleting the node. */
	if (node->data != data)
		return;

	if (number_of_elements == 1)
	{
		root = NULL;
		return;
	}

	Node* next = successor(node);
	/* Greatest element doesn't have a successor.*/
	if (next != node) 
	{
		splay(next);
		/* Reference of node can change, so we must look for it again. */
		node = search_private(data, root, root);
	}
	splay(node);
	to_string();

	/* Above we splayed node, so node is on the root. */
	node = root;
	Node* left_subtree = node->left;
	Node* right_subtree = node->right;
	if (right_subtree != NULL)
	{
		right_subtree->left = left_subtree;
		right_subtree->parent = NULL;
	}
	else if (left_subtree != NULL)
	{
		root = left_subtree;
		left_subtree->parent = NULL;
		return;
	}

	if (left_subtree != NULL)
		left_subtree->parent = right_subtree;
	root = right_subtree;
	number_of_elements -= 1;
}

/**
	* Function that finds the succesor of a node.
	* A successor is the smallest element bigger the current node.
	* A particular case is for the greatest element since it has no greater element;
	* so we return the reference for itself.
	* @param ptr The node that we are looking for it's successor.
	* @return Node reference to the successor.
*/
SplayTree::Node* SplayTree::successor(Node* ptr)
{
	if (ptr == NULL)
		return ptr;

	if (ptr->right != NULL)
		return subtree_smaller(ptr->right);
	else if (ptr != root && ptr->parent->left == ptr)
		return ptr->parent;

	/* Case for the greatest element in the tree. */
	if (ptr->right == NULL)
		return ptr;

	return NULL;
}

/**
	* Function that finds the smallest element of it's children.
	* The smallest element if the in the left corner.
	* @param ptr Node where the search is going to start.
	* @return Node reference to the smallest element; can be itself.
*/
SplayTree::Node* SplayTree::subtree_smaller(Node* ptr)
{
	Node* aux = ptr;
	while (aux->left != NULL)
		aux = aux->left;
	return aux;
}


