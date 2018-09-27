#include <bits/stdc++.h>
using namespace std;

/* Binary Search Tree  */
typedef struct node{
  int value;
  node* parent;
  node* left;
  node* right;
}root;
/* Create a new BTS node with the given value. */
node* create_node(int value){
  // Allocate memory for the new node	
  node* new_node = new (root);
  // Set the value 
  new_node -> value = value;
  // Initialize parent, left and right as a NULL.
  new_node -> parent = NULL;
  new_node -> left = NULL;
  new_node -> right = NULL;
  return new_node;
}
/* Initialize a BST as a root node with the given value. */
node* create_tree(int value){
  node* new_node = create_node(value);
  return new_node;
}
/* Search a node with the given value.*/
node* search(node* root, int value){
  if(root == NULL)
    return NULL;
  if(root -> value == value)
    return root;
  if(root -> value > value) 
    return search(root -> left, value);
  else
    return search(root -> right, value);
}
/* Insert a new node with the given value.*/
void insert(node* root, int value){
  node* temp = NULL;
  while(root != NULL){
    temp = root;
    if(root -> value >= value)
      root = root -> left;
    else
      root = root -> right;
  }
  node* new_node = create_node(value);
  new_node -> parent = temp;
  if(temp -> value > value)
    temp -> left = new_node;
  else
    temp -> right = new_node;  
}
/* Remove a node withe the given value.*/
void remove(node* root, int value){
  node* e = search(root,value);
  if(e == NULL)
    return;
  node* temp;
  if(e -> left != NULL && e -> right != NULL){
    temp = e -> left;
    while( temp -> right  != NULL)
      temp = temp -> right;
    e -> value = temp -> value;
    remove(temp, temp-> value);
  }else{
    node* parent = e -> parent;
    temp = (e -> left == NULL)? e -> right : e -> left;
    if(parent -> left == e)
      parent -> left = temp;
    else
      parent -> right = temp;
    delete(e);
  }
}
/* Print the nodes of the BST given in preorder.*/
void print_preorder(node* root){
  if(root == NULL)
    return;
  else{
    cout << root -> value << " ";
    print_preorder(root-> left);
    print_preorder(root-> right);
  }
}
int main(int argc, char** argv){
  /* Example */
  node* arbol = create_tree(15);
  int a[]= {10,4,6,12,11,14,13,1,22};
  int l = sizeof(a)/sizeof(*a);
  for(int i = 0; i < l; i++) 
    insert(arbol,a[i]);
  print_preorder(arbol);
  cout << "\nRemove 15\n";
  remove(arbol,15);
  print_preorder(arbol);
  cout << "\n";
  return 0;
}
