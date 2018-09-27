""" List (Doubly-Linked list) """

class List:
    """
        Doubly-Linked List implementation

        Attributes
        ----------
        head: Node
            Head Node

        tail: Node
            Tail Node

        size: int
            Number of elements in the list.

        Methods
        -------
        get_length()
        is_empty()
        insert(element)
            insert_back(element)
            insert_front(element)
        remove(element)
            remove_first()
            remove_last()
        search(element)
        contains(element)
        reverse()
        clear()
        get_first()
        get_last()
        get(index)
        index(element)
        copy()
    """
    class Node:
        """
            Node that contains the element.

            Attributes
            ----------
            element: element
                The key value the node holds.
            previous: Node
                A reference to the previous node in the list.
            next: Node
                A reference to the next node in the list.

        """
        def __init__(self, element):
            """
            Node constructor.

            Parameters
            ----------
            element: element
                The node element. 
            """
            self.element = element
            self.previous = None
            self.next = None

    def __init__(self):
        """
        List constructor.
        """
        self.head = None
        self.tail = None
        self.size = 0

    def __str__(self):
        """
        Returns the string representation of the list.

        Traverses all the nodes, concatenating in each step the string
        representation of the element contained in the node.
        :return: The string representation.
        :rtype: string
        """
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
        """
        Returns the string representation of the list.

        :return: The string representation.
        :rtype: string
        """
        return str(self)

    def get_length(self):
        """
        Returns the number of elements in the list.

        :return: The size of the list.
        :rtype: int
        """
        return self.size

    def is_empty(self):
        """
        Checks whether or not the list has no elements.

        :return: True is it has no element; false otherwise.
        :rtype: boolean
        """
        return self.head == None

    def insert(self, element):
        """
        Inserts a new node in the list, with the element specified as parameter.

        :param element: The element to be inserted in the list.
        """
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
        """
        Inserts the given element at the back of the list.

        :param element: The element to be inserted.
        """
        self.insert(element)

    def insert_front(self, element):
        """
        Inserts the given element at the front of the list.

        :param element: The element to be inserted.
        """
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
        """
        Deletes an element from the list. Decrements the size of the list after the operation.

        :param element: The element which we wish to remove.
        """
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
        """
        Deletes the element that is held at the head of the list. Decrements the size of the list
        after the operation.

        :param element: The element which we wish to remove.
        """
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
        """
        Deletes the element that is held at the tail of the list. Decrements the size of the list
        after the operation.

        :param element: The element which we wish to remove.
        """

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
        """
        Traverses the list, looking for the specified element.

        :param element: The element we are looking for.
        :return: None if the element is not found; the element of the node otherwise.
        :rtype: element
        """
        result = None
        current_node = self.head
        while current_node != None:
            if current_node.element is element:
                result = current_node
                break
            current_node = current_node.next
        return result.element

    def contains(self, element):
        """
        Verifies the result of the search query with the given element as parameter.

        :param element: The element which we wish to verify is it is in the list.
        :return: True is the list contains the element in one of its nodes; False otherwise.
        :rtype: boolean
        """
        return self.search(element) != None

    def reverse(self):
        """
        Reverses the given list so that the elements at the back will now be at the front and
        viceversa.

        :return: The resulting list after the operation.
        :rtype: List
        """
        reversed_list = List()
        current_node = self.head
        while current_node != None:
            reversed_list.insert_front(current_node.element)
            current_node = current_node.next
        return reversed_list

    def clear(self):
        """
        Removes all the elements from the list.
        """
        while self.size != 0:
            self.remove_last()

    def get_first(self):
        """
        Returns the first element in the list.

        :return: The element held at the head of the list.
        :rtype: element
        """
        if self.is_empty():
            return None
        return self.head.element

    def get_last(self):
        """
        Returns the last element in the list.

        :return: The element held at the tail of the list.
        :rtype: element
        """
        if self.is_empty():
            return None
        return self.tail.element

    def get(self, index):
        """
        Returns the element that is held at the node at the given index in the list.

        :param index: The query index.
        :return: The element at the given position.
        :rype: element
        """
        if index < 0 or index >= self.size:
            return None
        current_node = self.head
        count = 0
        while(count != index):
            current_node = current_node.next
            count += 1
        return current_node.element

    def index(self, element):
        """
        Returns the index of the first occurence of the given element.

        :param element: The element whose index we are looking for.
        :return: The index of the element.
        :rtype: int
        """
        current_node = self.head
        count = 0
        while current_node != None:
            if current_node.element is element:
                return count
            count += 1
            current_node = current_node.next
        return -1

    def copy(self):
        """
        Copies a list.

        :return: A copy of the list.
        :rtype: List
        """
        return self._copy_aux(List(), self.head)

    def _copy_aux(self, L, node):
        """
        Auxiliary method for copying a list.

        :param L: The list in which the current list will be copied.
        :param node: The node to be inserted.
        :return: The list resulting from inserting the element to L.
        :rtype: List
        """
        if node == None:
            return L
        else:
            L.insert_back(node.element)
            return self._copy_aux(L, node.next)