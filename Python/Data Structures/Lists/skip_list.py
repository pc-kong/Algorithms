import random

class SkipNode:
    """
    elem : value contained in the node.
    next : level where the node appears (list of pointers to the next nodes).
    """
    def __init__(self, height=0, elem=None):
        self.elem = elem
        self.next = [None]*height

    def __str__(self):
        string = "[" + str(self.elem) + "] "
        for node in reversed(self.next):
            if node != None:
                string += "[.]      "
            else:
                string += "[.]      "

        return string



    def __repr__(self):
        return str(self)

class SkipList:
    """
    head : current node.
    maxlevel : maximum level for the skip list.
    p : fraction of the nodes with level i references also having level i+1 references
    """
    def __init__(self, maxlevel, p):
        self.head = SkipNode(maxlevel,-1)
        self.maxlevel = maxlevel
        self.level = 0
        self.p = p

    """
    Choose the level of the node randomly.
    """
    def random_level(self):
        level = 1
        while random.random() < self.p and level < self.maxlevel:
            level += 1
        return level

    """
    Returns a list of nodes in each level that contains the greatest value that is smaller than 'elem'. 
    Start from the highest level.
    """
    def updateList(self, elem):
        #List of nodes.
        update = [None] * self.maxlevel
        current = self.head

        for i in reversed(range(len(current.next))):
            #search for the greatest x that is smaller than elem.
            while current.next[i] and current.next[i].elem < elem:
                current = current.next[i]
            update[i] = current

        return update

    """
    Search the node corresponding to the element.
    None if it is not present. 
    [Used for search/insert/delete]
    """
    def find(self, elem, update=None):
        if update == None:
            update = self.updateList(elem)
        if len(update) > 0 and update[0] != None:
            candidate = update[0].next[0]
            if candidate != None and candidate.elem == elem:
                return candidate
        return None

    """
    Insert the new node in each of the levels up related to his height;
    the last one choosen with the randomHeight function.
    """
    def insert(self, elem):
        level = self.random_level()
        snode = SkipNode(level, elem)
        update = self.updateList(elem)
        current = update[0].next[0]

        #If the element is not in the list.
        if current == None or current.elem != elem:
            #If the actual level of the list is smaller than the level of
            #the element to insert add reference to head.
            if level > self.level:
                for i in range(self.level+1,level):
                    update[i] = self.head
                self.level = level
            #Add the new node to each level.
            for i in range(level):
                snode.next[i] = update[i].next[i]
                update[i].next[i] = snode


    """
    Delete the node with value equal to elem; deletes it from all leves.
    """
    def remove(self, elem):
        update = self.updateList(elem)
        x = self.find(elem, update)
        if x != None:
            for i in range(len(x.next)):
                update[i].next[i] = x.next[i]

    def str_aux(self,nodes,actual,prev):
        if actual.next[0] == None:
            nodes.append(str(actual)+"\n")
            return nodes

        n = self.str_aux(nodes,actual.next[0],actual)
        actual = n[len(n)-1]

        if prev:
            string = ""
            str_prev = str(prev)
            str_act = str(actual)
            string += str_prev
            if len(str_prev) < len(str_act):
                for i in range(len(str_prev), len(str_act)):
                    if str_act[i] == "." or str_act[i] == "↓":
                        string += "↓"
                    else:
                        string += " "

            nodes.append(string+"\n")
        return nodes

    def __str__(self):
        string = ""
        arrows = "\n"
        for l in range(self.level):
            string += "    [.]  "
        for l in range(self.level):
            arrows += "     ↓   "
        string += arrows+"\n"

        actual = self.head.next[0]

        nodes = self.str_aux([],actual,None)

        for node in reversed(nodes):
            string += node
        return string

        """def __str__(self):
        string = ""
        arrows = "\n"
        for l in range(self.level):
            string += "    [.]  "
        for l in range(self.level):
            arrows += "     ↓   "
        string += arrows+"\n"

        actual = self.head.next[0]
        while actual:
            str_act = str(actual)
            string += str_act

            actual = actual.next[0]

            str_next = str(actual)

            if len(str_act) < len(str_next):
                for i in range(len(str_act),len(str_next)):
                    print(str_next[i])
                    if len(str_act) < i and str_next[i] == ".":
                        string += "↓"
                    else:
                        string += " "
            string += "\n"
        return string"""
    def __repr__(self):
        return str(self)

sl = SkipList(3,0.5)
sl.insert(2)
#print(sl)
#print(sl)
sl.insert(1)
#print(sl)
sl.insert(6)
sl.insert(3)
sl.insert(8)
print(sl)
