#1 wybor zajec
def tasks(A):
	stab = sorted(A, key = lambda x: x[1])
	max_tasks = 0
	#zaczynamy od czasu 0
	prev_end = 0
	n = len(stab)
	for i in range(n):
		#jezeli czynnosc zaczyna sie po poprzednio wybranej czynnosci
		#wybieramy ja i szukamy zajec konczacych sie po niej
		if(stab[i][0] >= prev_end):
			max_tasks+=1
			prev_end = stab[i][1]
	return max_tasks

#print(tasks([(0,10), (10,20), (5,15)]))

#2 huffman code
class Node:
	def __init__(self, val, left=None, right=None):
		self.val = val
		self.left = left
		self.right = right
	def __str__(self):
		return str(self.val)
	def __repr__(self):
		return str(self.val)

def heapify(tab,p):
	n = len(tab)
	l = (p+1)*2
	r = (p+1)*2 - 1
	target = p
	if l < n and tab[l].val < tab[target].val:
		target = l
	if r < n and tab[r].val < tab[target].val:
		target = r
	if target != p:
		tab[target], tab[p] = tab[p], tab[target]
		heapify(tab, target)

def bulid_heap(tab):
	n = len(tab)
	for i in range(n//2, -1, -1):
		heapify(tab, i)

def heap_pop(tab):
	n = len(tab)
	tab[0], tab[n-1] = tab[n-1], tab[0]
	a = tab.pop(n-1)
	heapify(tab, 0)
	return a

#b_len to ilosc bitow potrzebna na zakodowanie znaku
#inaczej jak gleboko w drzewie sie znajduje
def dfs_sum_bytes(node, b_len):
	s = 0
	#jezeli jest lisciem zwracamy ilosc bitow jakie zajmie zakodowanie znaku
	if node.left is None and node.right is None:
		return node.val*b_len
	else:
		#nie jest lisciem wiec sprawdzamy jego dzieci
		if node.left is not None:
			s += dfs_sum_bytes(node.left, b_len+1)
		if node.right is not None:
			s += dfs_sum_bytes(node.right, b_len+1)
	return s

def huffman_len(A):
	#tworzymy kopie A i zamieniamy jej elementy na Node'y
	tab = [Node(A[i]) for i in range(len(A))]
	bulid_heap(tab)
	while len(tab) > 1:
		#sciagamy Node z kopca
		x = heap_pop(tab)
		#tworzymy nowy Node, ktory laczy dwa najmniejsze nody nalezace do kopca
		new_node = Node(x.val+tab[0].val, tab[0], x)
		tab[0] = new_node
		heapify(tab,0)
	#kopiec zawiera jeden Node, ktory przechowuje drzewo binarne kodowania
	#przechodzimy graf w glab sumujac bity
	byte_size = dfs_sum_bytes(tab[0], 0)
	return byte_size


print(huffman_len([200, 700, 180, 120, 70, 30]))


#3 continous knapsack
def knapsack(A, k):
	#sortujemy malejaco co do wartosci na litr
	stab = sorted(A, reverse=True, key=lambda x : x[0]/x[1])
	max_val = 0
	for i in range(len(stab)):
		#jezeli mozemy, bierzemy wszystko
		if stab[i][1] < k:
			k-=stab[i][1]
			max_val+=stab[i][0]
		#jezeli nie, bierzemy ile mozemy i konczymy
		elif stab[i][1] >= k:
			max_val += stab[i][0]/stab[i][1]*k
			break
	return max_val

#print(knapsack([(1,1), (10,2), (11,2), (6,3)], 3))