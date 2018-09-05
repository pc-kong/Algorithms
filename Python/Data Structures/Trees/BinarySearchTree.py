""" Binary Search Tree """

from . import BinarySearchTreeNode

class BinarySearchTree:
    """
        Elemental Binary Search Tree

        Attributes
        ----------
        root=None: BinarySearchTreeNode
            Root Node

        Methods
        -------
    """

    def __init__(self, root=None):
        """
            Binary Search Tree Constructor
            
            Parameters
            ----------
            root=None: BinarySearchTreeNode
                Root Node
        """
        self.root = root

    def insert(self, element):
        """
            Insert an element in the Binary Search Tree

            Parameters
            ----------
            element : any type with comparable function
                New element to insert in the Tree
        """
        new_node = BinarySearchTreeNode(element)

        # When there is no root in the tree
        if self.root == None:
            self.root = new_node
            return None

        # Go to a leaf
        parent_node = None
        actual_node = self.root
        while actual_node != None:
            parent_node = actual_node
            if actual_node.getElement() <= element:
                actual_node = actual_node.getLeft()
            else:
                actual_node = actual_node.getRight()

        # We are already in a Leaf
        new_node.setParent(parent_node)
        if parent_node.getElement() <= element:
            parent_node.setLeft(new_node)
        else:
            parent_node.setRight(new_node)

    def search(self, element):
        """
            Search an element in the Binary Search Tree.

            Parameters
            ----------
            element : any type with comparable function
                New element to insert in the Tree.

            Returns
            -------
            BinarySearchTreeNode if there is the element in the Tree, None
            otherwise.
        """
        actual_node = self.root
        
        while actual_node != None:
            if actual_node.getElement() == element:
                return actual_node

            if actual_node.getElement() < element:
                actual_node = actual_node.getLeft()
            else:
                actual_node = actual_node.getRight()

        return None
