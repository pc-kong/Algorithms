# Splay 

# A simple node
class Node:
	def __init__(self, key):
		self.key = key
		self.left = self.right = None

class SplayTree:
	
	def __init__(self):
		self.root = None


	# Right rotate of the subtree
	#      x             y
	#    /   \         /   \
	#   y     C       A     x
	#  / \                 / \
	# A   B               B   C
	def zig(self, node_x):

		node_y = node_x.left

		if(node_y != None):
			node_x.left = node_y.right
			node_y.right = node_x
			return node_y
		return node_x
	
	# Left rotate of the subtree
	#      x             y  
	#    /   \         /   \  
	#   A     y       x     C  
	#        / \     / \      
	#       B   C   A   B 
	def zag(self, node_x):

		node_y = node_x.right

		if(node_y != None):
			node_x.right = node_y.left
			node_y.left = node_x;
			return node_y
		return node_x

	# Brings the key at the root and modifies the tree 
	# and returns the new root
	def splay(self,node, key):

		# Base case
		if (node == None):
			return None
		if(node.key == key):
			return node
		# The key is in the left subtree
		if(node.key > key):
			if(node.left == None): 
				return node

			# Zig-Zig
			if(node.left.key > key):
				# Bring the key to the root
				node.left.left = self.splay(node.left.left, key)
				node = self.zig(node)
				# Zig Zag
			elif(node.left.key < key):

				node.left.right = self.splay(node.left.right, key)
				# First do rotation for node.left
				if(node.left.right != None):
					node.left = self.zag(node.left)

			if(node.left != None):
				return self.zig(node)

			return node
		# The key is in the right subtree
		else:
			if(node.right == None): return node

			# Zag Zig
			if(node.right.key > key):

				node.right.left = self.splay(node.right.left, key)

				if(node.right.left != None):
					node.right = self.zig(node.right)
			# Zag Zag
			elif(node.right.key < key):
				node.right.right = self.splay(node.right.right, key)
				node = self.zag(node)

			# Making the second rotation for th root
			if(node.right != None):
				return self.zag(node)
			return node

	# Funtion to search in the splay tree
	def search(self, key):
		self.root = self.splay(self.root,key)
		return self.root.key if self.root.key == key else None
		
	# Funtion to insert a new key in the splay tree
	def insert(self,k):
		#If the tree is empty
		if self.root == None: 
			self.root = Node(k)
			return

		self.root = self.splay(self.root, k)

		
		# The new node
		newNode = Node(k)
		# If the root is greater, the root is the right child
		# of the new node
		if(self.root.key > k):
			newNode.right = self.root
			newNode.left = self.root.left
			self.root.left = None
			self.root = newNode
		# If the root key is smaller, make the root as the left
		# child of the new node
		else:
			newNode.left = self.root
			newNode.right = self.root.right
			self.right = None
			self.root = newNode


	def preOrder(self,node):
		if(node != None):
			print(node.key)
			self.preOrder(node.left)
			self.preOrder(node.right)

	def main(self):
		splayTree=SplayTree()
		splayTree.root = Node(10)
		splayTree.root.right = Node(5)
		splayTree.root.left = Node(20)
		splayTree.root.left.left = Node(4)
		splayTree.root.left.left.left = Node(3)
		splayTree.root.left.left.left.left = Node(2)
		print("Tenemos el siguiente arbol de prueba en preorden\n")
		self.preOrder(splayTree.root)
		print("Buscar 2")
		splayTree.search(2)
		self.preOrder(splayTree.root)
		print("Buscar 7")
		if(splayTree.search(7)==None):
			print("no esta")

		
		print("Agregar 7")
		splayTree.insert(7)
		self.preOrder(splayTree.root)
		
		

if __name__ == '__main__':
	SplayTree().main()





