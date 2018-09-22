""" Binary Search Tree """

from BinarySearchTreeNode import BinarySearchTreeNode

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

    def __init__(self, root=None, node_class=None):
        """
            Binary Search Tree Constructor
            
            Parameters
            ----------
            root=None: element
                Root element
        """
        if root != None:
            if node_class == None:
                self.root = BinarySearchTreeNode(root)
            else:
                self.root = node_class(root)
            self.length = 1
        else:
            self.root = None
            self.length = 0
        self.last_node_added = None

    def insert(self, element, node_class=None):
        """
            Insert an element in the Binary Search Tree

            Parameters
            ----------
            element : any type with comparable function
                New element to insert in the Tree
        """
        if node_class == None:
            new_node = BinarySearchTreeNode(element)
        else:
            new_node = node_class(element)

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
            if actual_node.get_element() == element:
                return actual_node

            if element < actual_node.get_element():
                actual_node = actual_node.get_left()
            else:
                actual_node = actual_node.get_right()

        return None

    def max_in_sub_tree(self, node):
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
        while ni.has_right():
            ni = ni.get_right()

        return ni

    def _remove_leaf(self, leaf):
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
        elif leaf.is_left_child():
            leaf.get_parent().left = None
        else:
            leaf.get_parent().right = None

        return leaf.get_element()

    def _remove_without_left(self, node):
        """
            Protected. Removes a node without left child.

            Parameters
            ----------
            node : Node to be removed

            Returns
            -------
            element : element of the Node removed
        """
        right = node.get_right()
        if node.get_parent() == None:
            self.root = right
        elif node.is_left_child():
            node.get_parent().set_left(right)
        else:
            node.get_parent().set_right(right)
        right.set_parent(node.get_parent())

        return node.get_element()

    def _remove_without_right(self, node):
        """
            Protected. Removes a node without right child.

            Parameters
            ----------
            node : Node to be removed

            Returns
            -------
            element : element of the Node removed
        """
        left = node.get_left()
        if node.get_parent() == None:
            self.root = left
        elif node.is_left_child():
            node.get_parent().set_left(left) 
        else:
            node.get_parent().set_right(left)
        left.set_parent(node.get_parent())

        return node.get_element()

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

        if to_remove.has_left():
            vi = to_remove
            to_remove = self.max_in_sub_tree(to_remove.get_left())
            vi.set_element(to_remove.get_element())

        if not to_remove.has_left() and not to_remove.has_right():
            self._remove_leaf(to_remove)
        elif not to_remove.has_left():
            self._remove_without_left(to_remove)
        else:
            self._remove_without_right(to_remove)

        self.length -= 1

    def _right_rotation(self, node):
        """
            Protected. The subtree of the node to the right

            Parameters
            ----------
            node : Binary Search Tree Node
        """
        if node == None:
            return None

        if not node.has_left():
            return None

        left = node.get_left()
        if node.get_parent() == None:
            self.root = left
        else:
            if node.is_left_child():
                node.get_parent().set_left(left)
            else:
                node.get_parent().set_right(left)

        left.set_parent(node.parent)
        node.set_left(left.get_right()) 
        if left.has_right():
            left.get_right().set_parent(node)
        left.set_right(node)
        node.set_parent(left)

    def _left_rotation(self, node):
        """
            Protected. The subtree of the node to the left

            Parameters
            ----------
            node : Binary Search Tree Node
        """
        if node == None:
            return None

        if not node.has_right():
            return None

        right = node.get_right()

        if node.get_parent() == None:
            self.root = right
        else:
            if node.is_left_child():
                node.get_parent().set_left(right)
            else:
                node.get_parent().set_right(right)

        right.set_parent(node.parent)
        node.set_right(right.get_left()) 
        if right.has_left():
            right.get_left().set_parent(node)
        right.set_left(node)
        node.set_parent(right)

