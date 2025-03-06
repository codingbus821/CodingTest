import sys

N, K = map(int, sys.stdin.readline().split())

info = []
dp = [0] * (K+1)

for _ in range(N):
    W, V = map(int, sys.stdin.readline().split())
    info.append([W, V])

for W, V in info:
    for i in range(W, K+1):
        if dp[i-W] + V > dp[i]:
            dp[i] = dp[i-W] + V
            
print(dp[-1])