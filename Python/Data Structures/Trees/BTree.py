import numpy as np

# Binary Search (Sorted Array)
def b_search(values, start, end, x):
    lower = start
    upper = end
    while (upper > lower + 1):
        if (x < values[(upper + lower) // 2]):
            upper = (upper + lower) // 2
        else:
            lower = (upper + lower) // 2
    return lower

# B-Tree
class BTree:

    # B-Tree Node
    class BNode:

        # B-Node Constructor
        def __init__(self, degree):
            self.keys = np.array([None] * (2 * degree - 1))
            self.children = np.array([None] * (2 * degree))
            self.num_keys = 0

        # Print keys rooted at B-Node
        def print_keys(self):
            j = 0
            while (j < self.num_keys):
                if (not self.is_leaf()):
                    self.children[j].print_keys()
                print self.keys[j].__str__(),
                j += 1
            # Greater child at j
            if (not self.is_leaf()):
                self.children[j].print_keys()

        # Full?? B-Node
        def is_full(self):
            return self.num_keys == self.keys.size

        # Leaf?? B-Node
        def is_leaf(self):
            return self.children[0] is None

        # Search at B-Node
        def search(self, x):
            # Binary Search on node keys
            lower = b_search(self.keys, 0, self.num_keys, x)
            # Found x here
            if (self.keys[lower] == x):
                return (self, lower)
            else:
                # Not found and we are in a leaf node
                if (self.children[0] is None):
                    return (None, -1)
                else:
                    # Picking lesser or greater child
                    if (self.keys[lower] < x):
                        lower += 1
                    return self.children[lower].search(x)

        # Split B-Node
        def split(self, parent, index):
            degree = self.children.size / 2
            # New B-Node
            aux = self.__class__(degree)
            # Initializing with B-1
            aux.num_keys = degree - 1
            # Copying last B-1 keys to new node
            j = 0
            while (j < degree - 1):
                aux.keys[j] = self.keys[j + degree]
                j += 1
            # Copying last B children to new node
            if (not self.is_leaf()):
                j = 0
                while (j < degree):
                    aux.children[j] = self.children[j + degree]
                    j += 1
            # Decreasing number of keys to B-1 in this node
            self.num_keys = degree - 1
            # Moving children of parent to the right at index
            j = parent.num_keys
            while (j >= index + 1):
                parent.children[j + 1] = parent.children[j]
                j -= 1
            # New children of parent is the new node
            parent.children[index + 1] = aux
            # Making space for new key
            j = parent.num_keys - 1
            while (j > index):
                parent.keys[j + 1] = parent.keys[j]
                j -= 1
            # New key of parent
            parent.keys[index] = self.keys[degree - 1]
            # Number of keys of parent increased by one
            parent.num_keys += 1

        # Insert Nonfull B-Node
        def insert_nonfull(self, x):
            j = self.num_keys - 1
            # B-Node is leaf node
            if (self.is_leaf()):
                # Moving greater keys to the right
                while (j >= 0 and x < self.keys[j]):
                    self.keys[j + 1] = self.keys[j]
                    j -= 1
                # Placing new key
                self.keys[j + 1] = x
                self.num_keys += 1
            # B-Node is internal node
            else:
                # Find correct location for new element (binary search on keys)
                j = b_search(self.keys, 0, self.num_keys, x) + 1
                # Child node is full (2B-1 keys)
                if (self.children[j].is_full()):
                    # Split child node
                    self.children[j].split(self, j)
                    # After splitting, select correct child to descend
                    if (x > self.keys[j]):
                        j += 1
                self.children[j].insert_nonfull(x)

        # Remove (Leaf Node)
        def basic_delete(self, index):
            # Moving keys to the left to fill "blank" space
            j = index + 1
            while (j < self.num_keys):
                self.keys[j - 1] = self.keys[j]
                j += 1
            self.num_keys -= 1

        # Find predecesor value of key at index
        def pred_value(self, index):
            # Lesser child
            aux = self.children[index]
            while (not aux.is_leaf()):
                # Greater descendant of lesser child
                aux = aux.children[aux.num_keys]
            # Last key of last (greater) descendant
            return aux.keys[aux.num_keys - 1]

        # Find succesor value of key at index
        def succ_value(self, index):
            # Greater child
            aux = self.children[index + 1]
            while (not aux.is_leaf()):
                # Lesser descendant of greater child
                aux = aux.children[0]
            # First key of last (lesser) descendant
            return aux.keys[0]

        # Merge children and value at index
        def merge_at(self, index):
            lesser = self.children[index]
            greater = self.children[index + 1]
            # Every internal node has at least B-1 keys (except root)
            # Both children have B-1 keys at this moment
            lesser.keys[lesser.num_keys] = self.keys[index];
            j = 0
            degree = lesser.num_keys + 1
            while (j < greater.num_keys):
                lesser.keys[j + degree] = greater.keys[j]
                j += 1
            # Lesser child is not a leaf, merge their children too...
            if (not lesser.is_leaf()):
                j = 0
                while (j <= greater.num_keys):
                    lesser.children[j + degree] = greater.children[j]
                    j += 1
            # Erasing value at index in current Node
            j = index + 1
            while (j < self.num_keys):
                self.keys[j - 1] = self.keys[j]
                j += 1
            # Erasing children of value at index
            j = index + 2
            while (j <= self.num_keys):
                self.children[j - 1] = self.children[j]
                j += 1
            # Free Memory???
            greater = None
            # Lesser child is full now
            lesser.num_keys = 2 * degree - 1
            self.num_keys -= 1

        # Remove (Parent Node)
        def complex_delete(self, index):
            degree = self.children.size / 2
            elem = self.keys[index]
            # Lesser Child (enough keys?)
            if (self.children[index].num_keys >= degree):
                temp = self.pred_value(index)
                self.keys[index] = temp
                self.children[index].delete(temp)
            # Greater Child (enough keys?)
            elif (self.children[index + 1].num_keys >= degree):
                temp = self.succ_value(index)
                self.keys[index] = temp
                self.children[index + 1].delete(temp)
            # Both children have less than B keys, merging values of children
            # and elem into lesser child
            else:
                self.merge_at(index)
                self.children[index].delete(elem)

        # Borrow key or merge to ensure subroot has B keys
        def borrow_key(self, index):
            degree = self.children.size / 2
            # Lesser sibling has at least B keys
            if (index > 0 and self.children[index - 1].num_keys >= degree):
                borrow_from_lesser(index)
            # Greater sibling has at least B keys
            elif (index < self.num_keys and
                  self.children[index + 1].num_keys >= degree):
                borrow_from_greater(index)
            # Merge with a sibling...
            else:
                new_index = index if (index < self.num_keys) else index - 1
                self.merge_at(new_index)

        # Borrowing key from B+? key lesser sibling
        def borrow_from_lesser(self, index):
            subroot = self.children[index]
            lesser = self.children[index - 1]
            j = subroot.num_keys - 1
            # Making space for new min value
            while (j >= 0):
                subroot.keys[j + 1] = subroot.keys[j]
                j -= 1
            # First (new) key of subroot = key at index - 1 from parent
            subroot.keys[0] = self.keys[index - 1]
            # Making space for new min child (Parent node?)
            if (not subroot.is_leaf()):
                j = subroot.num_keys
                while (j >= 0):
                    subroot.children[j + 1] = subroot.children[j]
                    j -= 1
                # New min child = greater child of lesser sibling
                subroot.children[0] = lesser.children[lesser.num_keys]
            # max key from lesser sibling goes to parent
            self.keys[index - 1] = lesser.keys[lesser.num_keys - 1]
            subroot.num_keys += 1
            lesser.num_keys -= 1

        # Borrowing key from B+? key greater sibling
        def borrow_from_greater(self, index):
            subroot = self.children[index]
            greater = self.children[index + 1]
            # last (new) key of subroot = key at index from parent
            subroot.keys[subroot.num_keys] = self.keys[index]
            # New greater child (Parent node?)
            if (not subroot.is_leaf()):
                subroot.children[subroot.num_keys + 1] = greater.children[0]
            # min key from greater sibling goes to parent node
            self.keys[index] = greater.keys[0]
            j = 1
            # Erasing min key from greater sibling
            while (j < greater.num_keys):
                greater.keys[j - 1] = greater.keys[j]
                j += 1
            # Erasing lesser child of greater sibling
            if (not greater.is_leaf()):
                j = 1
                while (j <= greater.num_keys):
                    greater.children[j - 1] = greater.children[j]
                    j += 1
            subroot.num_keys += 1
            greater.num_keys -= 1

        # Delete from subtree with this node as root
        def delete(self, x):
            degree = self.children.size / 2
            # Position of closest key with binary search
            pos = b_search(self.keys, 0, self.num_keys, x)
            # Found x
            if (self.keys[pos] == x):
                # Simple delete if node is leaf
                if (self.is_leaf()):
                    self.basic_delete(pos)
                # Complex delete for internal node
                else:
                    self.complex_delete(pos)
            # x not found in this node
            else:
                # delete fails
                if (self.is_leaf()):
                    print "El valor especificado no se encuentra en el arbol\n"
                    return
                # Greater child as subroot
                greater_root = self.keys[pos] < x
                # Ensure subroot has at least B keys
                if (self.children[pos].num_keys == degree - 1):
                    self.borrow_key(pos)
                # If we had to merge, recursion goes to lesser child
                if (greater_root and pos > self.num_keys):
                    self.children[pos - 1].delete(x)
                else:
                    self.children[pos].delete(x)



    # B-Tree Constructor
    def __init__(self, degree_):
        self.degree = degree_
        self.root = None

    # B-Tree Search
    def search(self, x):
        if (not self.root):
            print "El arbol esta vacio...\n"
            return
        return self.root.search(x)[0] is not None

    # B-Tree Print
    def print_values(self):
        if (not self.root):
            print "El arbol esta vacio...\n"
            return
        self.root.print_keys()

    # B-Tree Insert
    def insert(self, x):
        if (self.root is None):
            self.root = self.BNode(self.degree)
            self.root.keys[0] = x
            self.root.num_keys = 1
        else:
            if (self.root.is_full()):
                new_root = self.BNode(self.degree)
                temp = self.root
                self.root = new_root
                new_root.children[0] = temp
                temp.split(new_root, 0)
                new_root.insert_nonfull(x)
            else:
                self.root.insert_nonfull(x)

    # B-Tree Delete
    def delete(self, x):
        if (not self.root):
            print "El arbol esta vacio...\n"
            return
        self.root.delete(x)
        if (self.root.num_keys == 0):
            if (self.root.is_leaf()):
                self.root = None
            else:
                self.root = self.root.children[0]

b = BTree(3)

b.insert(10)
b.insert(20)
b.insert(30)
b.insert(40)
b.insert(50)
b.insert(60)
b.insert(70)
b.insert(80)
b.insert(90)


print b.print_values()

b.delete(60)
b.print_values()
print b.root.keys
print b.root.num_keys
print b.root.children[0].keys
print b.root.children[0].num_keys
print b.root.children[1].keys
print b.root.children[1].num_keys
print b.root.children[2].keys
print b.root.children[2].num_keys
b.delete(40)
b.print_values()
print b.root.keys
print b.root.num_keys
print b.root.children[0].keys
print b.root.children[0].num_keys
print b.root.children[1].keys
print b.root.children[1].num_keys
print b.root.children[2].keys
print b.root.children[2].num_keys
b.delete(50)
b.print_values()
print b.root.keys
print b.root.num_keys
print b.root.children[0].keys
print b.root.children[0].num_keys
print b.root.children[1].keys
print b.root.children[1].num_keys
print b.root.children[2].keys
print b.root.children[2].num_keys
b.delete(70)
b.print_values()
print b.root.keys
print b.root.num_keys
print b.root.children[0].keys
print b.root.children[0].num_keys
print b.root.children[1].keys
print b.root.children[1].num_keys
print b.root.children[2].keys
print b.root.children[2].num_keys
b.delete(90)
b.print_values()
print b.root.keys
print b.root.num_keys
print b.root.children[0].keys
print b.root.children[0].num_keys
print b.root.children[1].keys
print b.root.children[1].num_keys
print b.root.children[2].keys
print b.root.children[2].num_keys
