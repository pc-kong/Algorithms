""" Treap (Binary Search tree + heap) """

from TreapNode import TreapNode
from BinarySearchTree import BinarySearchTree
import random 
import types

class Treap(BinarySearchTree):
    """
        Max Treap

        Attributes
        ----------
        root=None: TreapNode
        
        last_node-added: TreapNode
        
        length: int
            Number of elements in the tree.

        Methods
        -------
        insert(element,priority)
        search(element,priority)
        remove(element,priority)
    """

    def __init__(self, root=None, priority = -1):
        """
            Treap Constructor
            
            Parameters
            ----------
            root=None: element
            Root element
        """

        BinarySearchTree.__init__(self, root, TreapNode)    
        if priority != -1:
            self.root.set_priority(priority)

    def search(self, element):
        """
            search an element in the Treap.
            this algorithm follows the method 
            for simple binary search trees

            Parameters
            ----------
            element : any comparable type
            
            returns
            -------
            TreapNode containing the element if it is
            in the treap, None oterwise.
        """
        return super().search(element)
    
    def insert(self, element, priority = -1, node_class=None):
        """
            Insert an element in the Binary Search Tree

            Parameters
            ----------
            element : any type with comparable function
                New element to insert in the Tree
            priority : integer or not specified for a random
        """
        #depending if add a node with a specified priorty we make a 
        #random priority or we use the parametter
        if priority == -1:
            if node_class == None:
                new_node = TreapNode(element)
            else:
                new_node = node_class(element)
        else:
            if node_class == None:
                new_node = TreapNode(element, priority)
            else:
                new_node = node_class(element, priority)

        # When there is no root in the tree
        if self.root == None:
            self.root = new_node
            self.last_node_added = new_node
            return None

        # Go to a leaf
        parent_node = None
        actual_node = self.root
        while actual_node != None:
            parent_node = actual_node
            if element <= actual_node.get_element():
                actual_node = actual_node.get_left()
            else:
                actual_node = actual_node.get_right()

        # We are already in a Leaf
        new_node.set_parent(parent_node)
        if  element <= parent_node.get_element():
            parent_node.set_left(new_node) 
        else:
            parent_node.set_right(new_node)

        self.last_node_added = new_node
        self.length += 1

        #rebalance the priorities
        actual_node = new_node
        while actual_node != None:
            parent = actual_node.get_parent()
            if parent != None and actual_node.get_priority() > parent.get_priority():
                if actual_node.is_left_child():
                    super()._right_rotation(parent)
                else:
                    super()._left_rotation(parent)
            actual_node = parent
    
    
    def remove(self, element, node_class=None):
        """
            Delete  an element in the Binary Search Tree

            Parameters
            ----------
            element : any type with comparable function
                New element to insert in the Tree
        """
        # When there is no root in the tree
        if self.root == None:
            return None

        # Go to a leaf
        actual_node = self.root
        while actual_node != None:
            if element == actual_node.get_element():
                break
            elif element < actual_node.get_element():
                actual_node = actual_node.get_left()
            else:
                actual_node = actual_node.get_right()
        
        if actual_node == None:
            return None

        #we pushh the node to a leaf
         
        parent_node = None
        while actual_node.get_left() != None or actual_node.get_right() != None:
            parent_node = actual_node
            right = actual_node.get_right()
            left = actual_node.get_left()
            if left == None:
                super()._left_rotation(actual_node)
            elif right == None:
                super()._right_rotation(actual_node)
            elif left.get_priority() <= right.get_priority():
                super()._left_rotation(actual_node)
            else:
                super()._right_rotation(actual_node)
        
        #remove the leaf
        if actual_node.is_left_child():
            actual_node.get_parent().set_left(None)
        else:
            actual_node.get_parent().set_right(None)

    def __str__(self):
        q1 = [self.root]
        q2 = []
        string = ""
        q_aux = []
        while q1 != [] or q2 != []:
            
            if q1 != []:
                actual = q1.pop(0)
                lenght = len(str(actual))
                spaces = 8 - lenght
                string += str(actual) + spaces*" "
                if actual != None:
                    q_aux.append(actual.get_left())
                    q_aux.append(actual.get_right())
                if q1 == []:
                    string += "\n"
                    q2 = q_aux
                    q_aux = []
            else:
                actual = q2.pop(0)
                lenght = len(str(actual))
                spaces = 8 - lenght
                string += str(actual) + spaces*" "
                if actual != None:
                    q_aux.append(actual.get_left())
                    q_aux.append(actual.get_right())
                if q2 == []:
                    string += "\n"
                    q1 = q_aux
                    q_aux = []
        return string

    def in_order(self):
        self.in_order_aux(self.root)

    # A function to do inorder tree traversal
    def in_order_aux(self, root):
        if root:
            # First recur on left child
            self.in_order_aux(root.get_left())
            # then print the data of node
            print(root)
            # now recur on right child
            self.in_order_aux(root.get_right())



    def post_order(self):
        self.post_order_aux(self.root)
    # A function to do postorder tree traversal
    def post_order_aux(self, root):
        if root:
            # First recur on left child
            self.post_order_aux(root.get_left())
            # the recur on right child
            self.post_order_aux(root.get_right())
            # now print the data of node
            print(root)


    def pre_order(self):
        self.pre_order_aux(self.root)
    # A function to do postorder tree traversal
    def pre_order_aux(self, root):
        if root:
            # First print the data of node
            print(root)
            # Then recur on left child
            self.pre_order_aux(root.get_left())
            # Finally recur on right child
            self.pre_order_aux(root.get_right())
    
    def __repr__(self):
            return str(self)

