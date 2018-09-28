#include <iostream>
#include <string>


using namespace std;

#ifndef SPLAYTREE_H
#define SPLAYTREE_H

/**
	* Class definition for Splay Trees.
	* Our implementations has:
	* 	A root reference that must not be lost.
	* 	A counter of the elements that are in the tree.
*/
class SplayTree
{
	public:
		/**
			* Class definition for Node.
			* This is part of the structure of the tree which will have:
			* An element to be stored.
			* 	Left reference to it's left subtree.
			* 	Right reference to it's right subtree. 
		*/
		class Node
		{
			public:
				int data;
				Node* left;
				Node* right;
				Node* parent;

				Node(int data, Node* left, Node* right, Node* parent);
				Node(int data);
		};

		SplayTree();
		
		bool is_empty();
		int size();
		int get_root_data();
		void to_string();	          

		void insert(int data);  
		Node* search(int key); 
		void remove(int data);

	private: 

		/* Attributes for Splay Trees. */
		Node* root;
		int number_of_elements;
		
		std::string pre_order(Node* ptr); 
		Node* successor(Node* ptr); 
		Node* subtree_smaller(Node* ptr);

		void zig(Node* ptr);
		void zag(Node* ptr);
		void splay(Node* ptr);

		void insert_private(Node* element, Node* ptr); 
		Node* search_private(int key, Node* root, Node* closer); 

};

#endif