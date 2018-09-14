""" Queue (FIFO) """

from RestrictedList import RestrictedList

class Queue(RestrictedList):

    def insert(self, element):
        if element == None:
            return None
        new_node = self.Node(element)
        if self.is_empty():
            self.head = new_node
        else:
            self.tail.next = new_node
        self.tail = new_node
