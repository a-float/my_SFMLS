#dla kazdej liczby obliczamy jej ilosc liczb jednokrotnych i wielokrotnych
#nastepnie przy pomocy radix sorta sortujemy je
#złożoność to N na obliczanie piękności i N na sortowanie 
#razem O(n)

def countingSort(arr, sort_v): 
	n = len(arr) 
  
	result = [0] * (n) 
	count = [0] * (10) 
	for i in range(0, n): #zliczanie cyfr
		count[arr[i][sort_v]] += 1
  
	for i in range(1,10): #nadanie własciwych indexów
		count[i] += count[i-1] 
  
	i = n-1
	while i>=0: #umieszczenie liczb na własciwych pozycjach
		index = arr[i][sort_v]
		result[count[(index)%10] - 1] = arr[i] 
		count[(index)%10] -= 1
		i -= 1
  
	i = 0 #kopiowanie wyniku
	for i in range(0,len(arr)): 
		arr[i] = result[i]

def pretty_sort(T): #radix sort
	tab = [calc_prettines(t) for t in T]
	#i to index elementów sortowanych tupli
	for i in range(2):
		countingSort(tab,i) 
	T[:] = [t[2] for t in tab] #usuwamy pomocnicze wartości zmieniamy daną tablicę

#zwraca tupla, zawierające parametry śliczności dla danej liczby
#liczba wielokrotnych, nie wielo ani nie jedno, dana liczba a
def calc_prettines(a):
	cp_a = a
	c1 = [0]*10
	while a > 0:
		c1[a%10]+=1
		a = a//10
	poj = 0 #liczba cyfr jednokrotnych
	wiel = 0 #liczba cyfr wielokrotnych
	for i in c1:
		if i == 1:poj+=1
		elif i != 0: wiel+=1
	return (wiel, 10-wiel-poj, cp_a)
	#sortujemy rosnąco względem liczby cyfr wielokrotnych
	#ale malejąco pod względem liczby cyfr jednokrotnych
	#lub inaczej rosnąco pod względem liczby cyfr nie wielokrotnych ani jednokrotnych

arr = [11112,243,3123123,5,1,5,1266,1267,126611,1256]
pretty_sort(arr)
print(arr)