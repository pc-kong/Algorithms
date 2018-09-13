""" Min and Max Heaps """

from HeapNode import HeapNode

class Heap:

    def __init__(self, is_min_heap = True, L = []):
        self.is_min_heap = is_min_heap
        self.tree = []
        if L != []:
            for x in L:
                node_to_insert = HeapNode(x, len(self.tree))
                self.tree.append(node_to_insert)
            self._heapify_down()

    def _swap(self, node_a, node_b):
        i = node_a.index
        j = node_b.index
        self.tree[i].element, self.tree[j].element = self.tree[j].element, self.tree[i].element

    def _is_valid_index(self, index):
        return index >= 0 and index < len(self.tree) and self.tree[index] != None

    def _has_left_child(self, node):
        return self._is_valid_index(node.get_left_child_index())

    def _has_right_child(self, node):
        return self._is_valid_index(node.get_right_child_index())

    def _has_parent(self, node):
        return self._is_valid_index(node.get_parent_index())

    def _get_left_child(self, node):
        if self._has_left_child(node):
            return self.tree[node.get_left_child_index()]

    def _get_right_child(self, node):
        if self._has_right_child(node):
            return self.tree[node.get_right_child_index()]

    def _get_parent(self, node):
        if self._has_parent(node):
            return self.tree[node.get_parent_index()]

    def get_list_nodes(self):
        return self.tree

    def __str__(self):
        return str(self.get_list_nodes())

    def __repr__(self):
        return str(self.get_list_nodes())

    def get_number_nodes(self):
        return len(self.tree)

    def is_empty(self):
        return self.get_number_nodes == 0

    def peek(self):
        return self.tree[0] if not self.is_empty() else None

    def insert(self, element):
        new_node = HeapNode(element, len(self.tree))
        self.tree.append(new_node)
        self._heapify_up(new_node)

    def remove(self):
        if self.is_empty():
            return None
        else:
            self._swap(self.tree[0], self.tree[-1])
            removed_node = self.tree.pop()
            self._heapify_down()
            return removed_node.element

    def search(self, element):
        for node in self.tree:
            if node == None:
                return False
            if node.element == element:
                return node
        return False

    def get(self, index):
        return self.tree[index] if self._is_valid_index(index) else None

    def _heapify_up(self, node):
        current_node = node
        if self.is_min_heap:
            while(self._has_parent(current_node) and self._get_parent(current_node).element > current_node.element):
                self._swap(self._get_parent(current_node), current_node)
                current_node = self._get_parent(current_node)
        else:
            while(self._has_parent(current_node) and self._get_parent(current_node).element < current_node.element):
                self._swap(self._get_parent(current_node), current_node)
                current_node = self._get_parent(current_node)
    
    def _heapify_down(self):
        current_node = self.tree[0]
        if self.is_min_heap:
            while(self._has_left_child(current_node)):
                smaller_child = self._get_left_child(current_node)
                if(self._has_right_child(current_node) and self._get_right_child(current_node).element < smaller_child.element):
                    smaller_child = self._get_right_child(current_node)
                if(current_node.element > smaller_child.element):
                    curr = smaller_child
                    self._swap(current_node, smaller_child)
                    current_node = curr
                    print("current node: ", current_node)
                    print(self._has_left_child(current_node))
                else:
                    break
        else:
            while(self._has_left_child(current_node)):
                larger_child = self._get_left_child(current_node)
                if(self._has_right_child(current_node) and self._get_right_child(current_node).element > larger_child.element):
                    larger_child = self._get_right_child(current_node)
                if(current_node.element < larger_child.element):
                    self._swap(current_node, larger_child)
                    current_node = larger_child
                else:
                    break
