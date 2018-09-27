""" Queue (FIFO) """

from RestrictedList import RestrictedList

class Queue(RestrictedList):
	"""
	In qeueues, the first element that was added is the first
	one to be removed.

	This class inherits from the RestrictedList class
	which already implements the removal method.
	"""

    def insert(self, element):
    	"""
    	Inserts an element into the Stack.
    	Since the element removed in the RestrictedList is the one
    	in the head of the list, then we need to insert the elements 
    	in the tail so that we respect the desired order of removal.

    	:param element: The element to be inserted.
    	"""
        if element == None:
            return None
        new_node = self.Node(element)
        if self.is_empty():
            self.head = new_node
        else:
            self.tail.next = new_node
        self.tail = new_node
