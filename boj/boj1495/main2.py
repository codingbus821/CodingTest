import sys

N, S, M = map(int, sys.stdin.readline().split())
v_list = list(map(int, sys.stdin.readline().split()))
dp = [[] for _ in range(N+1)]

dp[0].append(S)

for i in range(len(v_list)):
    for j in (dp[i]):
        if 0<=j+v_list[i]<=M and j+v_list[i] not in dp[i+1]:
            dp[i+1].append(j+v_list[i])
        if 0<=j-v_list[i]<=M and j-v_list[i] not in dp[i+1]:
            dp[i+1].append(j-v_list[i])

if len(dp[N]) == 0:
    print(-1)
else:
    print(max(dp[N]))