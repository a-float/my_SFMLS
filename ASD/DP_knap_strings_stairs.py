jumps = [1,3,2,1,1]
"""
Cel: dana jest tablica A zawierajaca liczby naturalne 
nie mniejsze od 1. poczatkowo stoimy na pozycji 0, 
wartość A[i] informuje nas jaka jest maksymalna dlugosc
skoku na następną pozycję. Należy policzyć na ile sposobów mogę 
przejść z pozycji 0 na pozycję n-1, przestrzegając reguł tablicy.
"""
def staircase(n):
	dp = [0]*(n+1)
	dp[0] = 0
	dp[1] = 1
	for i in range(2,n+1):
		for j in range(i):
			#print(i, i-j, jumps[j])
			if i-j <= jumps[j]:
				dp[i]+=dp[j]
	print(dp)


"""
Dostajemy  liczbę  naturalną  n. 
Naszym  zadaniem  jest  policzenie wszystkich
binarnych  (0/1)  string'ów bez jedynek obok siebie
"""
#moje
def countStrings(n):
	dp = [0]*(n+1)
	dp[0] = 1
	dp[1] = 2
	for i in range(2, n+1):
		dp[i] = dp[i-1] + dp[i-2]
	print(dp)

#z algo - output taki sam
def countStrings2(n): 
	array = [[-1 for i in range(2)]for j in range(n + 1)]
	array[0][0], array[0][1], array[1][0], array[1][1] = 0, 0, 1, 1
	for i in range(2, n + 1): 
		array[i][0] = array[i - 1][0] + array[i - 1][1] 
		array[i][1] = array[i - 1][0]
	print([array[i][0] + array[i][1] for i in range(n)])

""" the knapsack problem """
wt=[1,2,3,100]
p=[2,5,3,1000]
def knapsack_iter_dp(n,W):
	dp = [[0 for i in range(n)] for j in range(1,W+1)]
	for i in range(n):
		for w in range(W+1):
			if w == 0:
				dp[w][i] = 0
			elif wt[i] <= w:
				dp[w][i] = max(dp[w][i-1], p[i] + dp[w-wt[i]][i-1])
			else:
				dp[w][i] = dp[w][i-1]
	#for i in range(len(dp)):
		#print(dp[i])
	print(dp[W][n-1])

def knapsack_rec(i,w,dp):
	#nie ma czego dobierac
	if i==-1 or w==0:
		q = 0
		ans = []
	#zostalo juz obliczone
	elif dp[w-1][i][0] > 0 :
		q,ans = dp[w-1][i]
	#sprawdzamy czy wziecie przedmiotu na pozycji i jest oplacalne
	elif wt[i] <= w:
		a,ans1 = knapsack_rec(i-1,w,dp)
		b,ans2 = knapsack_rec(i-1,w-wt[i],dp)
		if a > p[i]+b:
			q = a
			ans = ans1
		else:
			q = b + p[i]
			ans = ans2+[i]
	#nie mozemy wziac przedmiotu na pozycji i
	else:
		q,ans = knapsack_rec(i-1,w,dp)
	dp[w-1][i] = [q,ans]
	return [q,ans]

def knapsack_recu_dp(n,W):
	#dwuwymiarowa tablica przechowujaca juz obliczone wartosci
	#dla kazdego maksymalnego udzwigu plecaka
	#przechowuje mkasymalny zysk z woboru z posrod
	#przedmiotow o indeksie <= i
	dp = [[[0,[]] for i in range(n)] for j in range(W)]
	return knapsack_rec(n-1,W,dp)
	

print(knapsack_recu_dp(len(wt),1010))