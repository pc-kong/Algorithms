""" Binary Search Tree """

from binarySearchTreeNode import BinarySearchTreeNode

class BinarySearchTree:
    """
        Elemental Binary Search Tree

        Attributes
        ----------
        root=None: BinarySearchTreeNode
            Root Node
        last_node_added: BinarySearchTreeNode
            Last node added in the Tree
        lenght: int
            Number of elements in the tree.

        Methods
        -------
        insert(element)
        search(element)
        remove(element)
    """

    def __init__(self, root=None, nodeClass=None):
        """
            Binary Search Tree Constructor
            
            Parameters
            ----------
            root=None: element
                Root element
        """
        if root != None:
            if nodeClass == None:
                self.root = BinarySearchTreeNode(root)
            else:
                self.root = nodeClass(root)
            self.length = 1
        else:
            self.root = None
            self.length = 0
        self.last_node_added = None

    def insert(self, element, nodeClass=None):
        """
            Insert an element in the Binary Search Tree

            Parameters
            ----------
            element : any type with comparable function
                New element to insert in the Tree
        """
        if nodeClass == None:
            new_node = BinarySearchTreeNode(element)
        else:
            new_node = nodeClass(element)

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
            if element <= actual_node.getElement():
                actual_node = actual_node.getLeft()
            else:
                actual_node = actual_node.getRight()

        # We are already in a Leaf
        new_node.setParent(parent_node)
        if  element <= parent_node.getElement():
            parent_node.setLeft(new_node)
        else:
            parent_node.setRight(new_node)

        self.last_node_added = new_node
        self.length += 1

    def search(self, element):
        """
            Search an element in the Binary Search Tree.

            Parameters
            ----------
            element : any type with comparable function
                Element to search in the Tree

            Returns
            -------
            BinarySearchTreeNode if there is the searched element in the Tree, None
            otherwise.
        """
        actual_node = self.root
        
        while actual_node != None:
            if actual_node.getElement() == element:
                return actual_node

            if element < actual_node.getElement():
                actual_node = actual_node.getLeft()
            else:
                actual_node = actual_node.getRight()

        return None

    def maxInSubTree(self, node):
        """
            Gets the max element in the node subtree

            Parameters
            ----------
            node : BinarySearchTreeNode
                Root node of the subtree

            Returns
            -------
            BinarySearchTreeNode if the node is not None, None otherwise.
        """
        ni = node
        while ni.hasRight():
            ni = ni.getRight()

        return ni

    def _removeLeaf(self, leaf):
        """
            Protected. Removes a Leaf

            Parameters
            ----------
            leaf : Leaf to be removed

            Returns
            -------
            element : element of the Leaf
        """
        if leaf.parent == None:
            self.root = None
        elif leaf.isLeftChild():
            leaf.getParent().left = None
        else:
            leaf.getParent().right = None

        return leaf.getElement()

    def _removeWithoutLeft(self, node):
        """
            Protected. Removes a node without left child.

            Parameters
            ----------
            node : Node to be removed

            Returns
            -------
            element : element of the Node removed
        """
        right = node.getRight()
        if node.getParent() == None:
            self.root = right
        elif node.isLeftChild():
            node.getParent().setLeft(right)
        else:
            node.getParent().setRight(right)
        right.setParent(node.getParent())

        return node.getElement()

    def _removeWithoutRight(self, node):
        """
            Protected. Removes a node without right child.

            Parameters
            ----------
            node : Node to be removed

            Returns
            -------
            element : element of the Node removed
        """
        left = node.getLeft()
        if node.getParent() == None:
            self.root = left
        elif node.isLeftChild():
            node.getParent().setLeft(left) 
        else:
            node.getParent().setRight(left)
        left.setParent(node.getParent())

        return node.getElement()

    def remove(self, element):
        """
            Removes the element sent.

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
            self._removeLeaf(to_remove)
        elif not to_remove.hasLeft():
            self._removeWithoutLeft(to_remove)
        else:
            self._removeWithoutRight(to_remove)

        self.length -= 1

    def _rightRotation(self, node):
        """
            Protected. The subtree of the node to the right

            Parameters
            ----------
            node : Binary Search Tree Node
        """
        if node == None:
            return None

        if not node.hasLeft():
            return None

        left = node.getLeft()
        if node.getParent() == None:
            self.root = left
        else:
            if node.isLeftChild():
                node.getParent().setLeft(left)
            else:
                node.getParent().setRight(left)

        left.setParent(node.parent)
        node.setLeft(left.getRight()) 
        if left.hasRight():
            left.getRight().setParent(node)
        left.setRight(node)
        node.setParent(left)

    def _leftRotation(self, node):
        """
            Protected. The subtree of the node to the left

            Parameters
            ----------
            node : Binary Search Tree Node
        """
        if node == None:
            return None

        if not node.hasRight():
            return None

        right = node.getRight()

        if node.getParent() == None:
            self.root = right
        else:
            if node.isLeftChild():
                node.getParent().setLeft(right)
            else:
                node.getParent().setRight(right)

        right.setParent(node.parent)
        node.setRight(right.getLeft()) 
        if left.hasLeft():
            right.getLeft().setParent(node)
        right.setLeft(node)
        node.setParent(right)

