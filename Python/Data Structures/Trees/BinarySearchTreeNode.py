""" Binary Search Tree Node """

class BinarySearchTreeNode:
    """
        Elemental Node in a Binary Search Tree

        Attributes
        ----------
        element: any type with comparable function
        parent: BinarySearchTreeNode
        left: BinarySearchTreeNode
        right: BinarySearchTreeNode

        Methods
        -------
        has_parent()
            returns True if there is a node parent, False otherwise

        has_left()
            returns True if this node has a left node, False otherwise

        has_right()
            returns True if this node has a right node, False otherwise
    """
    
    def __init__(self, element, parent=None, left=None, right=None):
        """
            Node Constructor
            
            Parameters
            ----------
            element : any type with comparable function
                Node element

            parent=None : BinarySearchTreeNode
                Node parent

            left=None : BinarySearchTreeNode
                Node in left

            right=None : BinarySearchTreeNode
                Node in right
        """
        self.element = element
        self.parent = parent
        self.left = left
        self.right = right
        
    def __str__(self):
        """
            Returns a String representation of this node.
        """
        return 'BinarySearchTreeNode(' + str(self.element) + ')'

    def __repr__(self):
        """
            Returns a String representation of this node.
        """
        return str(self)

    def __eq__(self, node):
        """
            Returns a Boolean depending if this and other node are equal.
        """
        if node == None or self.element != node.element:
            return False
        return self.left == node.left and self.right == node.right

    # All getters and setters
    def get_element(self):
        """
            Get the node element
            
            Returns
            -------
            element
                node element
        """
        return self.element

    def set_element(self, element):
        """
            Set the node element
            
            Parameters
            ----------
            element : any type with comparable function
                node element
        """
        self.element = element

    def get_parent(self):
        """
            Get the node element
            
            Returns
            -------
            parent : BinarySearchTreeNode
                Node parent
        """
        return self.parent

    def set_parent(self, parent):
        """
            Set the parent node
            
            Parameters
            ----------
            parent : BinarySearchTreeNode
                Parent node
        """
        self.parent = parent

    def get_left(self):
        """
            Get the node in left
            
            Returns
            -------
            element : BinarySearchTreeNode
                Node in left
        """
        return self.left

    def set_left(self, left):
        """
            Set the node in right
            
            Parameters
            ----------
            left : BinarySearchTreeNode
                Left node
        """
        self.left = left

    def get_right(self):
        """
            Get the node in right
            
            Returns
            -------
            right : BinarySearchTreeNode
                Node in right
        """
        return self.right

    def set_right(self, right):
        """
            Set the node in right
            
            Parameters
            ----------
            right : BinarySearchTreeNode
                Right node
        """
        self.right = right

    def has_parent(self):
        """
            Check if there is a parent
            
            Returns
            -------
            Boolean
                True if this node has a parent, False otherwise
        """
        return self.parent != None

    def has_left(self):
        """
            Check if there is a left node
            
            Returns
            -------
            Boolean
                True if this node has a left node, False otherwise
        """
        return self.left != None

    def has_right(self):
        """
            Check if there is a right node
            
            Returns
            -------
            Boolean
                True if this node has a right node, False otherwise
        """
        return self.right != None

    def is_left_child(self):
        """
            Check if this node is a left child.

            Returns
            -------
            Boolean
                True if this node is a Left child, False otherwise
        """
        if self.parent == None:
            return False

        return self.parent.left == self

    def is_right_child(self):
        """
            Check if this node is a right child.

            Returns
            -------
            Boolean
                True if this node is a right child, False otherwise
        """
        if self.parent == None:
            return False

        return self.parent.right == self
