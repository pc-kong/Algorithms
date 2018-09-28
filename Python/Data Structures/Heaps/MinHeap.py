""" Min-heaps """

from Heap import Heap

class MinHeap(Heap):
	"""
	Implements MinHeaps
	"""
    def __init__(self, L=[]):
    	"""
    	We construct a Heap with the min-ordering
    	property from a list which if not defined is 
    	to be empty.

    	:param L: The list from which we construct the
    	min-heap.
    	"""
        Heap.__init__(self, True, L)
