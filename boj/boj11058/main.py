import sys

N = int(sys.stdin.readline())

dp = list(i+1 for i in range(100))

for i in range(len(dp)):
    k = 2
    for j in range(i+3, len(dp)):
        dp[j] = max(dp[i]*k, dp[j])
        k += 1
        
print(dp[N-1])