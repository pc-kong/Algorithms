#include <bits/stdc++.h>

using namespace std;

//Structure that represents a node. 
typedef struct node {
	int value; //The value inside the node
	node *left, *right, *father; //Referencias al nodo padre, al subarbol izquierdo y al subarbol derecho.
	int factor; //Balance factor
	int height; //Height of the node;
}tree;

//Function that creates a new node
node* create_node(int value) {
	// Allocate memory for the new node	
	node* new_node = new (tree);
	// Set the value 
	new_node -> value = value;
	// Initialize all node values.
	new_node -> father = NULL;
	new_node -> left = NULL;
	new_node -> right = NULL;
	new_node -> height = 1;
	new_node -> factor = 0; 
	return new_node;
}  

//Function that returns true if the node is a right son.  
//The function assumes the father exists
bool is_right(node* son) {
	node* father = son -> father;
	if(father -> right == son)
		return true;
	return false;
} 

//Function that returns true if the node is a left son.  
//The function assumes the father exists
bool is_left(node* son) {
	node* father = son -> father;
	if(father -> left == son)
		return true;
	return false;
} 

//Funtion that returns the height of the node.
int get_height(node* node) {
	if(node == NULL)
		return 0;
	return node -> height;
}

//Function that re-calculates the balance factor of the given node  
int get_factor(node* node) {
	if(node == NULL)
		return 0;
	return abs(get_height(node -> left) - get_height(node -> right));
}

//Function that returns a node with the given value if it is in the tree, otherwise return null 
node* find(node* tree, int value) {
	if(tree == NULL)
    	return NULL;
  	if(tree -> value == value)
    	return tree;
  	if(value <= tree -> value) 
    	return find(tree -> left, value);
  	else
    	return find(tree -> right, value);
}

//Function that returns true if the given value is in the tree, otherwise returns false  
bool is_in_tree(node* tree, int value) {
	if(tree == NULL)
    	return false;
  	if(tree -> value == value)
    	return true;
  	if(value <= tree -> value) 
    	return is_in_tree(tree -> left, value);
  	else
    	return is_in_tree(tree -> right, value);
}

//Function that returns the node with the smaller element in the tree, otherwise returns null
node* smaller(node* tree) {
	node* small = tree;
	while(small -> left != NULL) 
		small = small -> left;
	return small;
}

/*																ROTATIONS
												     y                          x
												    / \     Right Rotation     /  \
												   x   T3   – – – – – – – >   T1   y 
												  / \       < - - - - - - -       / \
												 T1  T2       Left Rotation      T2  T3
*/ 

//Function that performs a right rotate on the subtree rooted with y 
//Returns the new root of the subtree
node* right_rotate(node* root) {
	node* grandfather = root -> father;
	node* son = root -> left;
	node* grandson = son -> right;
	if(grandfather != NULL) {
		son -> father = grandfather;
		if(is_right(root)) 
			grandfather -> right = son;
		else
			grandfather -> left = son;
	}
	son -> right = root;
	root -> father = son;
	root -> left = grandson;
	if(grandson != NULL)
		grandson -> father = root;
	son -> height = max(get_height(son -> left), get_height(son -> right)) + 1;
	root -> height = max(get_height(root -> left), get_height(root -> right)) + 1;
	son -> factor = get_factor(son);
	root -> factor = get_factor(root);
	return son;
}

//Function that performs a left rotate on the subtree rooted with y 
//Returns the new root of the subtree.
node* left_rotate(node* root) {
	node* grandfather = root -> father;
	node* son = root -> right;
	node* grandson = son -> left;
	if(grandfather != NULL) {
		son -> father = grandfather;
		if(is_right(root)) 
			grandfather -> right = son;
		else
			grandfather -> left = son;
	}
	son -> left = root;
	root -> father = son;
	root -> right = grandson;
	if(grandson != NULL)
		grandson -> father = root;
	son -> height = max(get_height(son -> left), get_height(son -> right)) + 1;
	root -> height = max(get_height(root -> left), get_height(root -> right)) + 1;
	son -> factor = get_factor(son);
	root -> factor = get_factor(root);
	return son;
}
/*
											   INSERTION AND DELETION

														Case 1													

								 		 z                                      y 
								        / \                                   /   \
								       y   T4      Right Rotate (z)          x      z
								      / \          - - - - - - - - ->      /  \    /  \ 
								     x   T3                               T1  T2  T3  T4
								    / \
								  T1   T2

								  						Case 2

									 z                               z                           x
								    / \                            /   \                        /  \ 
								   y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
								  / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
								T1   x                          y    T3                    T1  T2 T3  T4
								    / \                        / \
								  T2   T3                    T1   T2

								  						Case 3

										  z                                y
										 /  \                            /   \ 
										T1   y     Left Rotate(z)       z      x
										    /  \   - - - - - - - ->    / \    / \
										   T2   x                     T1  T2 T3  T4
										       / \
										     T3  T4					 
										     
										     			Case 4

								   z                            z                            x
								  / \                          / \                          /  \ 
								T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
								    / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
								   x   T4                      T2   y                  T1  T2  T3  T4
								  / \                              /  \
								T2   T3                           T3   T4 						

*/
//Function that inserts a new value into the tree and keeps the tree balanced. 
void insert(node* root, int value) {

	//First we perform a normal insertion like in a BST
	if(root == NULL) {
		root = create_node(value);
		return;
	}
	node* father = NULL;
	while(root != NULL) {
		father = root;
		if(value <= root -> value)
			root = root -> left;
		else
			root = root -> right;
	}
	node* new_node = create_node(value);
	new_node -> father = father;
	if(value <= father -> value) 
		father -> left = new_node;
	else
		father -> right = new_node;	 

	//End of the normal BST insertion. 
	//Now lets see if the tree is not balanced  

	node* grandfather = father -> father;
	int balance = get_factor(grandfather);

	//if the tree is not balanced then check in what kind of case the tree is
	if(balance > 1) {
		//case 1
		if(value <= father -> value && father -> value <= grandfather -> value) {
			right_rotate(grandfather);
			return;
		}
		//Case 2
		if(value > father -> value && father -> value <= grandfather -> value) {
			left_rotate(father);
			right_rotate(grandfather);
			return;
		}
		//Case 3
		if(value > father -> value && father -> value > grandfather -> value) {
			left_rotate(grandfather);
			return;
		}
		//Case 4
		if(value <= father -> value && father -> value > grandfather -> value) {
			right_rotate(father);
			left_rotate(grandfather);
		}
	} 
} 

//Function that deletes a value in the tree if the value exists and balance the tree if it is necessary.
void remove(node* root, int value) {
	//First perform a a normal BST deletion
	if(root == NULL) 
	  	return;
	if(!is_in_tree(root, value))
		return;
	while(root != NULL) {
		if(value == root -> value)
			break;
		if(value < root -> value) 
			root = root -> left;
		else
			root = root -> right;	 
	}
	// normal BST deletion case 1
	//One or both childs are NULL
	if(root -> left == NULL || root -> right == NULL) {
		node* child = root -> left ? root -> left : root -> right;
		if(child == NULL) {
			if(root -> father != NULL) {
				if(is_left(root))
					root -> father -> left = NULL;
				else
					root -> father -> right = NULL;
			}
			child = root;
			root = NULL;
		} else 
			*root = *child;
		delete(child);
	} else { // The root has 2 childs
		node* small = smaller(root -> right);
		root -> value = small -> value;
		remove(root -> right, small -> value); 
	}

	//End of the normal BST Delete
	//Now we just need to balance the tree if is necessary
	if(root == NULL)
		return;
	root -> height = max(get_height(root -> left), get_height(root -> right)) + 1;
	int balance = get_height(root -> left) - get_height(root -> right);
	//Case 1
	if (balance > 1 && get_height(root -> left -> left) - get_height(root -> left -> right) >= 0) {
    	right_rotate(root);
    	return;
	}
    // Case 2
    if (balance > 1 && get_height(root -> left -> left) - get_height(root -> left -> right) < 0) { 
        left_rotate(root->left); 
        right_rotate(root);
        return;
    } 
    //Case 3
    if (balance < -1 && get_height(root -> right -> left) - get_height(root -> right -> right) <= 0) {
        right_rotate(root);
        return;
    }
    // Case 4
    if (balance < -1 && get_height(root -> right -> left) - get_height(root -> right -> right) > 0) 
    { 
        right_rotate(root->right); 
        left_rotate(root);
        return;
    } 
} 

//DFS just to print the tree
void print_dfs(node* root){
  	if(root == NULL)
    	return;
  	else{
    	cout << root -> value << " ";
    	print_dfs(root-> left);
    	print_dfs(root-> right);
  	}
} 


int main(int argc, char const *argv[]) {
	//SOME EXAMPLE OF THE USING OF THIS PROGRAM
	node* root = create_node(1);
	insert(root, 2); 
    insert(root, 3); 
    insert(root, 4);
    print_dfs(root);
	cout << endl;
	remove(root, 2);
	print_dfs(root);
	cout << endl;

	return 0;
}
