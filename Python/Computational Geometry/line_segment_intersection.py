""" Line Segment Intersection """

import heapq

class Point:
    """
        Point in the Cartesian Plane
    """

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def set_segment(self, segment):
        self.segment = segment

    # These functions are just for sorting the point with y
    def __gt__(self, point):
        return self.y > point.y

    def __eq__(self, point):
        return self.y == point.y

    def __lt__(self, point):
        return self.y < point.y

    def __repr__(self):
        return "Point(" + str(self.x) + ", " + str(self.y) + ")"


class Segment:
    """
        Line Segment
    """
    
    def __init__(self, point1, point2):
        self.point1 = point1
        self.point2 = point2

    def cross_product(self, point):
        d1 = point.x - self.point2.x
        d2 = point.y - self.point2.y
        d3 = self.point1.x - self.point2.x
        d4 = self.point1.y - self.point2.y

        return d1*d4 - d2*d3

    def get_point_direction(self, point):
        cross_product = self.cross_product(point)
        if cross_product == 0:
            return 0
        return cross_product // abs(cross_product)

    def point_is_in_segment(self, point):
        cross_product = Segment(self.point1, point).cross_product(self.point2)
        if cross_product != 0:
            return False

        dot_product = (point.x-self.point1.x) * (self.point2.x-self.point1.x)+(
            (point.y - self.point1.y)*(self.point2.y - self.point1.y)
        )
        if dot_product < 0:
            return False

        squared_length_ab = (self.point2.x-self.point1.x)*(self.point2.x-self.point1.x)+(
            (self.point2.y - self.point1.y)*(self.point2.y - self.point1.y)
        )
        if squared_length_ab < dot_product:
            return False

        return True

    def segment_intersects(self, segment):
        o1 = self.get_point_direction(segment.point1)
        o2 = self.get_point_direction(segment.point2)
        o3 = segment.get_point_direction(self.point1)
        o4 = segment.get_point_direction(self.point2)

        # General Case
        if o1 != o2 and o3 != o4:
            return True

        # Special Cases
        if o1 == 0 and Segment(self.point1, segment.point1).point_is_in_segment(self.point2):
            return True

        if o2 == 0 and Segment(self.point1, segment.point2).point_is_in_segment(self.point2):
            return True

        if o3 == 0 and Segment(segment.point1, self.point1).point_is_in_segment(segment.point2):
            return True

        if o4 == 0 and Segment(segment.point1, self.point2).point_is_in_segment(segment.point2):
            return True

        return False

class RangeTree:

    class Node:

        def __init__(self, element, left=None, right=None, father=None):
            self.element = element
            self.left = left
            self.right = right
            self.father = father

        def __repr__(self):
            return "Node - " + str(self.element) + " L(" + ("None" if self.left == None else str(self.left)) + ")  R(" + ("None" if self.right == None else str(self.right)) + ")"


    def __init__(self, root=None):
        self.root = root
        if self.root != None:
            self.root.father = None

    def insert(self, element):
        new_node = RangeTree.Node(element)
        current_node = self.root

        if current_node == None:
            self.root = new_node
            return None

        # Until we find a leaf
        while current_node.left != None and current_node.right !=None:
            if current_node.element.x >= element.x:
                current_node = current_node.left
            else:
                current_node = current_node.right

        new_aux = RangeTree.Node(current_node.element)
        if current_node.element.x >= element.x:
            current_node.element = element
            current_node.left = new_node
            current_node.right = new_aux
            new_node.father = current_node
            new_aux.father = current_node
        else:
            current_node.left = new_aux
            current_node.right = new_node
            new_node.father = current_node
            new_aux.father = current_node
            self.update_tree(new_node)

    def update_tree(self, max_node):
        current_node = max_node.father
        while current_node.father != None and current_node.father.right == current_node:
            current_node = current_node.father

        if current_node.father == None:
            return None

        current_node.father.element = max_node.element

    def __repr__(self):
        return str(self.root)


def plane_sweep_algorithm(segments):
    priority_queue = []
    range_tree = RangeTree()
    for segment in segments:
        segment.point1.set_segment(segment)
        segment.point2.set_segment(segment)
        heapq.heappush(priority_queue, segment.point1)
        heapq.heappush(priority_queue, segment.point2)
        range_tree.insert(segment.point1)
        print(segment.point1)
        print(range_tree)
        range_tree.insert(segment.point2)
        print(segment.point2)
        print(range_tree)
        




point1 = Point(0, 0)
point2 = Point(2, 2)
point3 = Point(0, 1)
point4 = Point(1, -1)
point5 = Point(2, 3)

segment1 = Segment(point1, point2)
segment2 = Segment(point1, point3)
segment3 = Segment(point3, point4)
segment4 = Segment(point2, point4)
segment5 = Segment(point2, point5)


plane_sweep_algorithm([segment1, segment2, segment3])
