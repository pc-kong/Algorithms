""" Max-heaps """

from Heap import Heap

class MaxHeap(Heap):
	"""
	Implements MaxHeaps
	"""
    def __init__(self, L=[]):
    	"""
    	We construct a Heap with the max-ordering
    	property from a list which if not defined is 
    	to be empty.

    	:param L: The list from which we construct the
    	max-heap.
    	"""
        Heap.__init__(self, False, L)
