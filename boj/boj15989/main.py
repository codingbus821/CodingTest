import sys

T = int(sys.stdin.readline())

ret_list = []

for _ in range(T):
    n = int(sys.stdin.readline())
    ret_list.append(n)
    
dp = [0] * (max(ret_list)+1)
dp[0] = 1

for k in range(1, 4):
    for i in range(1, (max(ret_list)+1)):
        if i >= k:
            dp[i] += dp[i-k]

for i in ret_list:
    print(dp[i])