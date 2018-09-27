""" Splay Tree """

from BinarySearchTreeNode import BinarySearchTreeNode
from BinarySearchTree import BinarySearchTree

class Splay(BinarySearchTree):

    def inorder(self):
        self._inorder(self.root)

    def _inorder(self, node):
        if node != None:
            self._inorder(node.left)
            print("Node element:", str(node.element))
            left = "None" if node.left == None else str(node.left.element)
            right = "None" if node.right == None else str(node.right.element)
            print("\tLeft node element:", left)
            print("\tRight node element:", right)
            self._inorder(node.right)

    def _zig(self, node):
        super()._right_rotation(node)

    def _zag(self, node):
        super()._left_rotation(node)

    def _splay(self, node):
        while True:
           parent = node.parent 
           if parent == None:
               break
           grandparent = parent.parent
           if grandparent == None:
                if parent.left is node:
                    self._zig(parent)
                else:
                    self._zag(parent)
                break
           if grandparent.left is parent:
                if parent.left is node:
                    self._zig(grandparent)
                    self._zig(parent)
                else:
                    self._zag(parent)
                    self._zig(grandparent)
           else:
                if parent.left is node:
                    self._zig(parent)
                    self._zag(grandparent)
                else:
                    self._zag(grandparent)
                    self._zag(parent)

    def insert(self, element):
        super().insert(element)
        new_node = self.last_node_added
        self._splay(new_node)

    def remove(self, element):
        to_remove = self.search(element)
        if to_remove == None:
            return False
        self._splay(to_remove)
        p = to_remove.left
        if p == None:
            super()._remove_without_left(to_remove)
        while p.right != None:
            p = p.right
        if to_remove.right != None:
            p.right = to_remove.right
            to_remove.right.parent = p
        self.root = to_remove.left
        self.root.parent = None
 
    def search(self, element):
        found_node = super().search(element)
        if found_node == None:
            return None
        else:
            self._splay(found_node)
            return found_node
