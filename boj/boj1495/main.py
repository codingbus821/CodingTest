import sys

N, S, M = map(int,sys.stdin.readline().split())

dp = [[False] * (M+1) for _ in range(N+1)]
v_list = list(map(int, sys.stdin.readline().split()))

dp[0][S] = True

for i in range(N):
    for j in range(M+1):
        if dp[i][j] == True:
            if j + v_list[i] <= M:
                dp[i+1][j + v_list[i]] = True
            if j - v_list[i] >= 0:
                dp[i+1][j - v_list[i]] = True

ans = -1

for i in range(M+1):
    if dp[N][i] == True:
        ans = max(ans, i)
        
print(ans)