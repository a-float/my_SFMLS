#nie musimy sortować całej listy
#odnajdujemy wartość elementu na pozycjach p i q O(n)
#następnie przechodzimy przez tablicę i do wyniku dodajemy wszystkie elementy,
#o wartości pomiedzy znalezionymi O(n)
#wartośći tablicy są różne, więc odnalezione elementy będą własciwe
#złożoność liniowa

def partition(arr,l,r): 
    wall = l-1       
    pivot = arr[r] 
  
    for j in range(l , r): 
        if arr[j] < pivot: #na lewo
            wall+=1
            arr[wall],arr[j] = arr[j],arr[wall] #swap
    arr[wall+1],arr[r] = arr[r],arr[wall+1] #pivot do miejsce
    return wall+1
  

def ntaNajmniesza(arr, l, r, k): 
    mid = partition(arr, l, r-1) 
    if (mid-l == k-1):
        return arr[mid] 
    if (mid-l > k-1):
        return ntaNajmniesza(arr, l, mid-1, k) 
    return ntaNajmniesza(arr, mid+1, r, k-mid+l-1) 


def section(T, p, q):
	s = ntaNajmniesza(T, 0, len(T), p)
	e = ntaNajmniesza(T, 0, len(T), q) #można przyśpieszyć zawężając obszar poszukiwań do elementów po indeksie p
	res = []
	for i in arr:
		if(i>=s and i<= e):
			res.append(i)
	return res

arr = [3,4,7,2,6,4,12,54,3,7,234,86,56]
p,q = 5,9
print(section(arr,p,q))