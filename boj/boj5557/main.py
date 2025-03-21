import sys

N = int(sys.stdin.readline())
num_list = list(map(int,sys.stdin.readline().split()))

dp = [[0] * N for _ in range(21)]
dp[num_list[0]][0] = 1

for i in range(1,N-1):
    s_list = []
    for j in range(21):
        if dp[j][i-1] != 0:
            s_list.append(j)
    for k in s_list:
        if 0<=(k + num_list[i])<=20:
            dp[k + num_list[i]][i] = dp[k][i-1] + dp[k + num_list[i]][i]
        if 0<=(k - num_list[i])<=20:
            dp[k - num_list[i]][i] = dp[k][i-1] + dp[k - num_list[i]][i]

print(dp[num_list[-1]][N-2])