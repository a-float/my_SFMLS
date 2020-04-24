tab = [[1,1,1,1],
	   [1,1,1,1],
	   [1,2,2,1],
	   [1,2,2,1]]

def szach_dp(n):
	dp = [[0 for i in range(n)] for i in range(n)]
	for i in range(n):
		for j in range(n):
			q = float("inf")
			if i == 0 and j == 0:
				q = 0
			if i>0:
				q = min(q, dp[i-1][j])
			if j>0:
				q = min(q, dp[i][j-1])
			dp[i][j] = q+tab[i][j]
	print(dp)

#szach_dp(4)

def longest_substring_dp_rec(i,j,a,b,dp):
	q = 0
	if i<0 or j<0:
		return 0
	if dp[i][j] > 0:
		return dp[i][j]
	if a[i] == b[j]:
		q = longest_substring_dp_rec(i-1,j-1,a,b,dp)+1
	else:
		c = longest_substring_dp_rec(i-1,j,a,b,dp)
		d = longest_substring_dp_rec(i,j-1,a,b,dp)
		q = max(c,d)
	dp[i][j] = q
	return q 

def longest_substring_dp(a,b):
	dp = [[0 for i in range(len(b))] for i in range(len(a))]
	print(longest_substring_dp_rec(len(a)-1, len(b)-1, a, b, dp))
	#for i in range(len(a)):
		#print(dp[i])

a = "aaaaaba"
b = "basdaababba"
longest_substring_dp(a,b)