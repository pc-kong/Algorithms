""" AVL Tree """

from binarySearchTreeNode import BinarySearchTreeNode
from binarySearchTree import BinarySearchTree
import types

class AVLTree(BinarySearchTree):
    """
        AVL Tree.

        To see more information about AVL Trees read:
            https://en.wikipedia.org/wiki/AVL_tree

    """

    class AVLNode(BinarySearchTreeNode):
        """
            Node used in AVL Trees

            Attributes
            ----------
            element: any type with comparable function
            parent: AVLNode
            left: AVLNode
            right: AVLNode
            height: Node distance to the farthest leaf.
        """

        def __init__(self, element, parent=None, left=None, right=None):
            """
                AVL Node Constructor

                Parameters
                ----------
                element : any type with comparable function
                    Node element

                parent=None : AVL Node
                    Node parent

                left=None : AVL Node
                    Node in left

                right=None : AVL Node
                    Node in right
            """
            BinarySearchTreeNode.__init__(self, element, parent, left, right)
            self.height = 0

        def __str__(self):
            """
                Returns a String representation of this node.
            """
            return 'AVLNode(' + str(self.element) + ')'

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
            return self.height == node.height and self.left == node.left and (
                self.right == node.right)

        def getHeight(self):
            """
                Gets the node height
            """
            return self.height

        def calculateHeight(self):
            """
                Calculates the Node height
            """
            if self.left == None and self.right == None:
                self.height = 0
            elif self.left == None:
                self.height = self.right.height + 1
            elif self.right == None:
                self.height = self.left.height + 1
            else:
                self.height = max(self.left.height, self.right.height) + 1

        def calculateBalance(self):
            """
                Calculates the balance between the left and right childs
            """
            if self.left == None and self.right == None:
                return 0
            if self.left == None:
                return -(self.right.height + 1)
            if self.right == None:
                return self.left.height + 1
            return (self.left.height - self.right.height)


    def __init__(self, root=None):
        """
            AVL Tree Constructor

            Parameters
            ----------
            root=None: element
                Root element
        """
        BinarySearchTree.__init__(self, root, self.AVLNode)

    def rebalance(self, node):
        """
            Recursive function. The AVL from the node given until the tree is
            well balanced.

            Parameters
            ----------
            node: AVL Node
                AVL Node where we start rebalancing.
        """
        if node == None:
            return None
        node.calculateHeight()

        if node.calculateBalance() == 2:
            if node.left.calculateBalance() == -1:
                left = node.left
                super().leftRotation(left)
                left.calculateHeight()
                left.parent.calculateHeight()
            super().rightRotation(node)
            node.calculateHeight()
            return self.rebalance(node.parent.parent)
        if node.calculateBalance() == -2:
            if node.right.calculateBalance() == 1:
                right = node.right
                super().rightRotation(right)
                right.calculateHeight()
                right.parent.calculateHeight()
            super().leftRotation(node)
            node.calculateHeight()
            return self.rebalance(node.parent.parent)
        
        return self.rebalance(node.parent)

    def insert(self, element):
        """
            Inserts an element in the Tree and rebalances the Tree if it
            is necessary.

            Parameters
            ----------
            element: any type with a comparable function
        """
        super().insert(element, nodeClass=self.AVLNode)
        new_node = self.last_node_added
        self.rebalance(new_node)

    def remove(self, element):
        """
            Removes the element given and rebalances the Tree if it is
            necessary.

            Parameters
            ----------
            element : element to remove in the tree
        """

        to_remove = self.search(element)

        if to_remove == None:
            return None

        if to_remove.hasLeft():
            vi = to_remove
            to_remove = self.maxInSubTree(to_remove.getLeft())
            vi.setElement(to_remove.getElement())

        if not to_remove.hasLeft() and not to_remove.hasRight():
            super()._removeLeaf(to_remove)
        elif not to_remove.hasLeft():
            super()._removeWithoutLeft(to_remove)
        else:
            super()._removeWithoutRight(to_remove)

        self.length -= 1

        self.rebalance(to_remove.parent)

