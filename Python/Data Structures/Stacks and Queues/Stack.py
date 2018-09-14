""" Stack (LIFO) """

from RestrictedList import RestrictedList

class Stack(RestrictedList):

    def insert(self, element):
        if element == None:
            return None
        new_node = self.Node(element)
        if self.is_empty():
            self.tail = new_node
        else:
            new_node.next = self.head
        self.head = new_node
