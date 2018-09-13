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
        hasParent()
            returns True if there is a node parent, False otherwise

        def hasLeft()
            returns True if this node has a left node, False otherwise

        def hasRight()
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
    def getElement(self):
        """
            Get the node element
            
            Returns
            -------
            element
                node element
        """
        return self.element

    def setElement(self, element):
        """
            Set the node element
            
            Parameters
            ----------
            element : any type with comparable function
                node element
        """
        self.element = element

    def getParent(self):
        """
            Get the node element
            
            Returns
            -------
            parent : BinarySearchTreeNode
                Node parent
        """
        return self.parent

    def setParent(self, parent):
        """
            Set the parent node
            
            Parameters
            ----------
            parent : BinarySearchTreeNode
                Parent node
        """
        self.parent = parent

    def getLeft(self):
        """
            Get the node in left
            
            Returns
            -------
            element : BinarySearchTreeNode
                Node in left
        """
        return self.left

    def setLeft(self, left):
        """
            Set the node in right
            
            Parameters
            ----------
            left : BinarySearchTreeNode
                Left node
        """
        self.left = left

    def getRight(self):
        """
            Get the node in right
            
            Returns
            -------
            right : BinarySearchTreeNode
                Node in right
        """
        return self.right

    def setRight(self, right):
        """
            Set the node in right
            
            Parameters
            ----------
            right : BinarySearchTreeNode
                Right node
        """
        self.right = right

    def hasParent(self):
        """
            Check if there is a parent
            
            Returns
            -------
            Boolean
                True if this node has a parent, False otherwise
        """
        return self.parent != None

    def hasLeft(self):
        """
            Check if there is a left node
            
            Returns
            -------
            Boolean
                True if this node has a left node, False otherwise
        """
        return self.left != None

    def hasRight(self):
        """
            Check if there is a right node
            
            Returns
            -------
            Boolean
                True if this node has a right node, False otherwise
        """
        return self.right != None

    def isLeftChild(self):
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

    def isRightChild(self):
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
