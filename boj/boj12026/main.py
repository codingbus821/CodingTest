import sys

N = int(sys.stdin.readline())

block = sys.stdin.readline()

dp = [1000000] * ((len(block))-1)
visit = [False] * ((len(block))-1)
visit[0] = True
dp[0] = 0

for i in range(len(block)):
    for j in range(i+1, len(block)):
        if block[i] == 'B' and block[j] == 'O':
            dp[j] = min(dp[j], dp[i] + (j-i)**2)
            visit[j] = True
        if block[i] == 'O' and block[j] == 'J':
            dp[j] = min(dp[j], dp[i] + (j-i)**2)
            visit[j] = True
        if block[i] == 'J' and block[j] == 'B':
            dp[j] = min(dp[j], dp[i] + (j-i)**2)
            visit[j] = True

if dp[N-1] == 1000000:
    print(-1)
else:
    print(dp[N-1])