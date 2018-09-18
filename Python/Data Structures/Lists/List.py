""" List (Doubly-Linked list) """

class List:

    class Node:
        
        def __init__(self, element):
            self.element = element
            self.previous = None
            self.next = None

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def __str__(self):
        current_node = self.head
        list_string = "["
        while current_node != None:
            list_string += str(current_node.element)
            current_node = current_node.next
            if current_node != None:
                list_string += ", "
        list_string += "]"
        return list_string

    def __repr__(self):
        return str(self)

    def get_length(self):
        return self.size

    def is_empty(self):
        return self.head == None

    def insert(self, element):
        if element == None:
            return
        new_node = self.Node(element)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.previous = self.tail
            self.tail = new_node
        self.size += 1

    def insert_back(self, element):
        self.insert(element)

    def insert_front(self, element):
        if element == None:
            return
        new_node = self.Node(element)
        if self.is_empty():
            self.head = new_node
            self.tail = new_node
        else:
            self.head.previous = new_node
            new_node.next = self.head
            self.head = new_node
        self.size += 1

    def remove(self, element):
        removed_node = self.search(element)
        if removed_node == None:
            return
        if self.head == self.tail:
            self.head = None
            self.tail = None
        elif self.head == removed_node:
            self.head = self.head.next
            self.head.previous = None
        elif self.tail == removed_node:
            self.tail = self.tail.previous
            self.tail.next = None
        else:
            removed_node.previous.next = removed_node.next
            removed_node.next.previous = removed_node.previous
        self.size -= 1

    def remove_first(self):
        if self.is_empty():
            return
        removed_element = self.head.element
        self.head = self.head.next
        if self.size == 1:
            self.tail = None
        else:
            self.head.previous = None
        self.size -= 1
        return removed_element

    def remove_last(self):
        if self.is_empty():
            return
        removed_element = self.tail.element
        self.tail = self.tail.previous
        if self.size == 1:
            self.head = None
        else:
            self.tail.next = None
        self.size -= 1
        return removed_element

    def search(self, element):
        result = None
        current_node = self.head
        while current_node != None:
            if current_node.element is element:
                result = current_node
                break
            current_node = current_node.next
        return result.element

    def contains(self, element):
        return self.search(element) != None

    def reverse(self):
        reversed_list = List()
        current_node = self.head
        while current_node != None:
            reversed_list.insert_front(current_node.element)
            current_node = current_node.next
        return reversed_list

    def clear(self):
        while self.size != 0:
            self.remove_last()

    def get_first(self):
        if self.is_empty():
            return None
        return self.head.element

    def get_last(self):
        if self.is_empty():
            return None
        return self.tail.element

    def get(self, index):
        if index < 0 or index >= self.size:
            return None
        current_node = self.head
        count = 0
        while(count != index):
            current_node = current_node.next
            count += 1
        return current_node.element

    def index(self, element):
        current_node = self.head
        count = 0
        while current_node != None:
            if current_node.element is element:
                return count
            count += 1
            current_node = current_node.next
        return -1

    def copy(self):
        return self._copy_aux(List(), self.head)

    def _copy_aux(self, L, node):
        if node == None:
            return L
        else:
            L.insert_back(node.element)
            return self._copy_aux(L, node.next)
