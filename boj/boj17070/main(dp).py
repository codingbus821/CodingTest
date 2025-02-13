N = int(input())

m = []
ans = 0
dp = [[[0] * 3 for _ in range(N)] for _ in range(N)]

for _ in range(N):
    m.append(list(map(int, input().split())))

if m[N-1][N-1] == 1:
    print(0)
    exit()

for i in range(1, N):
    if m[0][i] == 1:
        break
    dp[0][i][0] = 1

for i in range(1, N):
    for j in range(1, N):
        if m[i][j] == 0:
            dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2]
            dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2]
        if m[i][j] == 0 and m[i-1][j] == 0 and m[i][j-1] == 0:
            dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2]

print(sum(dp[N-1][N-1]))