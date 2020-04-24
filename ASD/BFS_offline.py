class Queue:
	def __init__(self):
		self.tab = []
		self.end = 0
		self.start = 0
	def push(self,val):
		if(self.end >= len(self.tab)):
			self.tab.append(val)
		else:
			self.tab[self.end] = val
		self.end+=1
	def pop(self):
		self.start+=1
		return self.tab[self.start-1]
	def is_empty(self):
		return self.start==self.end

class Node:
	def __init__(self, n):
		self.index = n
		self.visited = False
		self.parent = None
		self.dist = 0
	def __repr__(self):
		return "("+str(self.parent)+" "+str(self.dist)+")"

def BFS(start_index, arr):
	nodes = [Node(i) for i in range(len(arr))]
	nodes[start_index].visited = True
	que = Queue()
	que.push(nodes[start_index])

	while not que.is_empty():
		curr_node = que.pop()
		for i in range(len(arr[curr_node.index])):
			if arr[curr_node.index][i] == 1 and nodes[i].visited == False:
				nodes[i].visited = True
				nodes[i].parent = curr_node.index
				nodes[i].dist = curr_node.dist+1
				que.push(nodes[i])

	print(nodes)

arr=[[0,1,1,0],[0,0,0,1],[0,1,0,1], [0,0,0,0]]
BFS(0,arr)