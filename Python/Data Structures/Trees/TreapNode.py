""" Treap Node """
from BinarySearchTreeNode import BinarySearchTreeNode
import random 

class TreapNode(BinarySearchTreeNode):
    """
        Elemental Node in a Treap

        Attributes
        ----------
        element: any comparable type
        priority: positive integer
        parent: TreapNode
        left: TreapNode
        rigth: TreapNode

        Methods
        -------

        All methods in BynarySearchTreeNode

        set_priority(n)
            set the priority of this node to n
        
        get_priority()
            return the priority of this node
    """

    def __init__(self, element,priority = -1 
                ,parent=None, left=None, right=None):
        
        #call the constructor from BinarytTreeNode
        BinarySearchTreeNode.__init__(self, element)
        
        #add the new attribute
        if priority == -1:
            self.priority = random.randint(1,1000)
        else:
            self.priority = priority


    def __str__(self):
        """
            return string from the node
        """
        return '(' + str(self.element) + '/' + str(self.priority) + ')'

    def __repr__(self):
        """
            return string from the node
        """
        return str(self)

    def __eq__(self, node):
        """
            Returns a Boolean depending if this and other node are equal.
        """
        if node == None or self.element != node.element or self.priority != node.priority:
            return False
        return self.left == node.left and self.right == node.right

    def get_priority(self):
        """
            Get the priority from this node
            
            Returns
            -------
            priority : positive integer
        """
        return self.priority

    def set_priority(self, priority):
        """
            Set the priority for this node

            Parameters
            ----------
            priority : positive integer
        """

        self.priority = priority














