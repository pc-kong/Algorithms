""" Min-heaps """

from Heap import Heap

class MinHeap(Heap):

    def __init__(self, L=[]):
        Heap.__init__(self, True, L)
