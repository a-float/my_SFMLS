#cena, waga, wysokosc
arr = [(10,5,20),(8,6,17), (12,7,31), (2,3,1), (3,1,8)]
P = [(5,10,3), (7,8,12), (2,7,3)]

def knapsack2d(arr, max_w, max_h):
	dp = [[[0 for a in range(len(arr))] for b in range(max_h+1)] for c in range(max_w+1)]
	for i in range(len(arr)):
		for h in range(max_h+1):
			for w in range(max_w+1):
				if h==0 or w==0:
					dp[w][h][i] = 0
				elif h>=arr[i][2] and w>=arr[i][1]:
					c_w = arr[i][1]
					c_h = arr[i][2]
					#bierzemy lub nie bierzemy ele o indeksie i
					dp[w][h][i] = max(dp[w-c_w][h-c_h][i-1]+arr[i][0],
						dp[w][h][i-1])
				else:
					dp[w][h][i] = dp[w][h][i-1]
	print(dp[max_w][max_h][len(arr)-1])

#knapsack2d(arr, 30, 45)

#arr with data, avaible weight, avaible height, max index
def knap_rec(arr, W, H, i):

	if W==0 or H==0 or i<0:
		return 0
	elif W>=arr[i][1] and H>=arr[i][2]:
		return max(arr[i][0]+knap_rec(arr, W-arr[i][1], H-arr[i][2], i-1), knap_rec(arr,W,H,i-1))
	else:
		return knap_rec(arr, W, H, i-1)

def knapsack2d_recu(arr, max_w, max_h):
	dp = [[[0 for a in range(len(arr))] for b in range(max_h+1)] for c in range(max_w+1)]
	print(knap_rec(arr, max_w, max_h, len(arr)-1))

knapsack2d_recu(arr, 30, 45)