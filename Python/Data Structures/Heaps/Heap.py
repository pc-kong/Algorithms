""" Heap """

class Heap:

    def __init__(self, isMinHeap = True, L = []):
        self.isMinHeap = isMinHeap
        self.tree = L
        if L != []:
            self._heapifyDown()

    def _getLeftChildIndex(self, parentIndex):
        return 2 * parentIndex + 1

    def _getRightChildIndex(self, parentIndex):
        return 2 * parentIndex + 2

    def _getParentIndex(self, childIndex):
        return (childIndex - 1) // 2

    def _hasLeftChild(self, index):
        return self._getLeftChildIndex(index) < len(self.tree)

    def _hasRightChild(self, index):
        return self._getRightChildIndex(index) < len(self.tree)

    def _hasParent(self, index):
        return self._getParentIndex(index) >= 0

    def _getLeftChild(self, index):
        return self.tree[self._getLeftChildIndex(index)]

    def _getRightChild(self, index):
        return self.tree[self._getRightChildIndex(index)]

    def _getParent(self, index):
        return self.tree[self._getParentIndex(index)]

    def _swap(self, i, j):
        self.tree[i], self.tree[j] = self.tree[j], self.tree[i]

    def _isValidIndex(self, index):
        return index >= 0 and index < len(self.tree) and self.tree[index] is not None

    def _heapifyUp(self):
        index = len(self.tree) - 1
        if self.isMinHeap:
            while(self._hasParent(index) and self._getParent(index) > self.tree[index]):
                self._swap(self._getParentIndex(index), index)
                index = self._getParentIndex(index)
        else:
            while(self._hasParent(index) and self._getParent(index) < self.tree[index]):
                self._swap(self._getParentIndex(index), index)
                index = self._getParentIndex(index)

    def _heapifyDown(self):
        index = 0
        if self.isMinHeap:
            while(self._hasLeftChild(index)):
                smallerChildIndex = self._getLeftChildIndex(index)
                if(self._hasRightChild(index) and self._getRightChild(index) < self._getLeftChild(index)):
                    smallerChildIndex = self._getRightChildIndex(index)
                if(self.tree[index] < self.tree[smallerChildIndex]):
                    break
                else:
                    self._swap(index, smallerChildIndex)
                    index = smallerChildIndex
        else:
            while(self._hasLeftChild(index)):
                largerChildIndex = self._getLeftChildIndex(index)
                if(self._hasRightChild(index) and self._getRightChild(index) > self._getLeftChild(index)):
                    largerChildIndex = self._getRightChildIndex(index)
                if(self.tree[index] > self.tree[largerChildIndex]):
                    break
                else:
                    self._swap(index, largerChildIndex)
                    index = largerChildIndex

    def getElements(self):
        return self.tree

    def numberOfElements(self):
        return len(self.tree)

    def isEmpty(self):
        return self.numberOfElements() == 0

    def peek(self):
        return self.tree[0] if not self.isEmpty() else None

    def insert(self, element):
        self.tree.append(element)
        self._heapifyUp()
 
    def popHeap(self):
        if self.isEmpty():
            return None
        else:
            element = self.tree[0]
            self.tree[0] = self.tree[-1]
            self.tree.pop()
            self._heapifyDown()
            return element

    def search(self, element):
        for e in self.tree:
            if e is None:
                return False
            if e is element:
                return True
        return False

    def get(self, index):
        return self.tree[index] if self._isValidIndex(index) else None
