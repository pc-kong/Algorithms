""" Linear structures with restricted insertion, peeking and deletion operations """

from abc import ABCMeta, abstractmethod

class RestrictedList:
    """
    Implements the generic list that will later on serve for the Stack and Queue implementation.

    Attributes
     ----------
    head: Node
        Head Node

    tail: Node
        Tail Node

    Methods
    -------
    is_empty()
    insert(element) [abstract method]
    remove(element)
    peek()
    """
    
    __metaclass__ = ABCMeta

    class Node:
        """
        Node that contains the element.

        Attributes
        ----------
        element: element
            The key value the node holds.
        next: Node
            A reference to the next node in the list.
        """

        def __init__(self, element):
            """
            Constructor for the nodes.

            Parameter
            --------

            element: element
                The element to be stored in the node.
            """
            self.element = element
            self.next = None

    def __init__(self):
        """
        Restricted List constructor.
        """
        self.head = None
        self.tail = None
        
    def __str__(self):
        """
        Returns the string representation of the Restricted List
        by traversing it starting from the head and concatenating
        the string representation of each element.

        :return: The string representation of the list.
        :rtype: string
        """
        current_node = self.head
        list_string = "["
        while current_node != None:
            list_string += str(current_node.element)
            current_node = current_node.next
            if current_node != None:
                list_string += ", "
        list_string += "]"
        return list_string

    def __eq__(self, other):
        """
        Checks it the list is the same as some other list.

        Parameter
        ---------
        other: RestrictedList
            The other object to be compared to this list.
        """
        if other == None:
            return False
        node_a = self.head
        node_b = other.head
        while node_a != None and node_b != None:
            # Comparing the elements one by one.
            if node_a.element != node_b.element:
                return False
            node_a = node_a.next
            node_b = node_b.next
        return node_a is node_b

    def is_empty(self):
        """
        Checks whether the list is empty or not.

        :return: True if is is empty, false otherwise.
        :rtype: boolean
        """
        return self.head == None

    # Abstract method to be implemented by Stacks and Queues.
    @abstractmethod
    def insert(self, element): pass

    def remove(self):
        """
        Deletes the element in the head of the list.

        :return: The element that was removed.
        :rtype: element
        """
        if self.is_empty():
            return None
        element = self.head.element
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
        return element

    def peek(self):
        """
        Returns the element that is in the head of the list, without removing it.

        :return: The element stored in the head.
        :rtype: element
        """
        if self.is_empty():
            return None
        return self.head.element
