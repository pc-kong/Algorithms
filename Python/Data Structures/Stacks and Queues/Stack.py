""" Stack (LIFO) """

from RestrictedList import RestrictedList

class Stack(RestrictedList):
	"""
	In stacks, the last element that was added is the first
	one to be removed.

	This class inherits from the RestrictedList class
	which already implements the removal method.
	"""
    def insert(self, element):
    	"""
    	Inserts an element into the Stack.
    	Since the element removed in the RestrictedList is the one
    	in the head of the list, then we need to insert those elements
    	there.

    	:param element: The element to be inserted.
    	"""
        if element == None:
            return None
        new_node = self.Node(element)
        if self.is_empty():
            self.tail = new_node
        else:
            new_node.next = self.head
        self.head = new_node
