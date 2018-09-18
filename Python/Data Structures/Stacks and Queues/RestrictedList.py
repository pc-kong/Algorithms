""" Linear structures with restricted insertion, peeking and deletion operations """

from abc import ABCMeta, abstractmethod

class RestrictedList:
    
    __metaclass__ = ABCMeta

    class Node:

        def __init__(self, element):
            self.element = element
            self.next = None

    def __init__(self):
        self.head = None
        self.tail = None
        
    def __str__(self):
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
        if other == None:
            return False
        node_a = self.head
        node_b = other.head
        while node_a != None and node_b != None:
            if node_a.element != node_b.element:
                return False
            node_a = node_a.next
            node_b = node_b.next
        return node_a is node_b

    def is_empty(self):
        return self.head == None

    @abstractmethod
    def insert(self, element): pass

    def remove(self):
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
        if self.is_empty():
            return None
        return self.head.element
