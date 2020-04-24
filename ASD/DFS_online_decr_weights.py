import random

class Node:
	def __init__(self, n):
		self.neigbours = n
		self.weight = random.randrange(100)
		self.parent = None
	def __repr__(self):
		return "("+str(self.weight)+")"

def DFS(G):
	nodes = [Node(G[i]) for i in range(len(G))]
	nodes[0].weight = 100
	print(DFS_recur(0,nodes, 3))
	

def DFS_recur(curr, nodes, target):
	for i in nodes[curr].neigbours:
		print("from",curr)
		print("trying", i ,nodes[curr].weight, nodes[i].weight)
		if nodes[i].weight < nodes[curr].weight:
			if(i == target):
				return True
			elif DFS_recur(i, nodes, target) == True:
					return True
	return False

G = [[1,2,4],[0,2,3],[3,1,0],[],[0]]
DFS(G)