""" Max-heaps """

from Heap import Heap

class MaxHeap(Heap):

    def __init__(self, L=[]):
        Heap.__init__(self, False, L)
