class Node:
	def __init__(self, n):
		self.neigbours = n
		self.visited = False
		self.parent = None
	def __repr__(self):
		return "("+str(self.parent)+")"

def DFS(G):
	nodes = [Node(G[i]) for i in range(len(G))]
	for i in range(len(nodes)):
		if nodes[i].visited == False:
			DFS_recur(i,nodes)
	print(nodes)

def DFS_recur(curr, nodes, parent = None):
	nodes[curr].visited = True
	nodes[curr].parent = parent
	for i in nodes[curr].neigbours:
		if nodes[i].visited == False:
			DFS_recur(i, nodes, curr)

G = [[1,2,4],[0,2,3],[3,1,0],[],[0]]
DFS(G)