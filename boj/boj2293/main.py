n, k = map(int, input().split())
ret = 0
n_list = [int(input()) for _ in range(n)]

dp = [0 for _ in range(k+1)]

dp[0] = 1

for i in n_list:
    for j in range(i, k+1):
        dp[j] = dp[j] + dp[j-i]

print(dp[-1])