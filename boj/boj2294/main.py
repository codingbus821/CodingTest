n, k = map(int, input().split())

n_set = set()

for _ in range(n):
    n_set.add(int(input()))

n_list = list(n_set)

dp = [111111] * (k+1)
dp[0] = 0

for i in n_list:
    for j in range(i, k+1):
        dp[j] = min(dp[j], dp[j-i] + 1)

if dp[-1] == 111111:
    print(-1)
else: 
    print(dp[-1])