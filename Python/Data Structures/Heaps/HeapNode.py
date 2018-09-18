""" Heap Node """

class HeapNode:

    def __init__(self, element, index):
        self.element = element
        self.index = index

    def __str__(self):
        return '(' + str(self.element) + ', ' + str(self.index) + ')'

    def __repr__(self):
        return str(self)

    def __eq__(self, node):
        if node == None or self.element != node.element:
            return False
        return self.index == node.index

    def get_element(self):
        return self.element

    def set_element(self, element):
        self.element = element

    def get_index(self):
        return self.index

    def set_index(self, index):
        self.index = index

    def get_left_child_index(self):
        return (2 * self.index) + 1

    def get_right_child_index(self):
        return (2 * self.index) + 2

    def get_parent_index(self):
        return (self.index - 1) // 2
