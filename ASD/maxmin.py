from queue import PriorityQueue

class Node:
	def __init__(self):
		self.cons = []
		self.visited = False;
		self.width = -float("infinity")
	def __str__(self):
		return str(self.width)

graph = [Node() for _ in range(5)]
edges = [(0,1,1),(1,3,10),(0,3,5),(0,2,2),(2,4,5),(3,4,2),(2,3,3)]
for s,e,w in edges:
	graph[s].cons.append((e,w))
	graph[e].cons.append((s,w))

que = PriorityQueue(-1)
start = 0
end = 4
graph[start].width = float("infinity")
que.put((0, start))

def check(graph, c):
	print("visiting", c)
	graph[c].visited = True
	for t,w in graph[c].cons:
		if graph[t].visited == False:
			print(t,w)
			alt = max(graph[t].width, min(graph[c].width, w))
			print("alt is ",alt, "width[t] is", graph[t].width)
			if alt > graph[t].width:
				print("setting ",t," to ",alt)
				graph[t].width = alt
				que.put((-alt, t))


while que:
	w = que.get()[1]
	check(graph, w)
	if graph[end].visited:
		print(graph[end].width)
		break
