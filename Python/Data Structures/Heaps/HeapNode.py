""" Heap Node """

class HeapNode:
    """
    Node for heaps.

    Attributes
    ----------
    element: element
        The element to be stored in the node.

    index: int
        The index of the node in the array representing the heap.
    """
    def __init__(self, element, index):
        """
        Initializes the node.

        :param element: The element of the node.
        :param index: The index of the node in the heap.
        """
        self.element = element
        self.index = index

    def __str__(self):
        """
        Returns a string representation of the node.

        :return: The string repreentation.
        :rtype: string
        """
        return '(' + str(self.element) + ', ' + str(self.index) + ')'

    def __repr__(self):
        """
        Returns a string representation of the node.

        :return: The string repreentation.
        :rtype: string
        """
        return str(self)

    def __eq__(self, node):
        """
        Checks if the node is equal to some other node.

        :param node: The other node with which to compare.
        :return: True is they are the same; false otherwise.
        :rtype: boolean
        """
        if node == None or self.element != node.element:
            return False
        return self.index == node.index

    def get_element(self):
        """
        Returns the element contained in the node.

        :return: The element contained in the node.
        :rtype: element
        """
        return self.element

    def set_element(self, element):
        """
        Sets the element of the node.

        :param element: The element which we wish to store in the node.
        """
        self.element = element

    def get_index(self):
        """
        Retuns the index of the node.

        :return: The index of the node.
        :rtype: int
        """
        return self.index

    def set_index(self, index):
        """
        Sets the index of the node.

        :param index: The index to be set.
        """
        self.index = index

    def get_left_child_index(self):
        """
        Gets the index of the left child of this node.

        :return: The index of the left child.
        :rtype: int
        """
        return (2 * self.index) + 1

    def get_right_child_index(self):
        """
        Gets the index of the right child of this node.

        :return: The index of the right child.
        :rtype: int
        """
        return (2 * self.index) + 2

    def get_parent_index(self):
        """
        Gets the index of the parent of this node.

        :return: The index of the parent.
        :rtype: int
        """
        return (self.index - 1) // 2