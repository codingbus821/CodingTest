from sys import stdin

N = int(stdin.readline())

T=[0]*(N+1)
P=[0]*(N+1)
dp = [0]*(N+1)

for i in range(N):
    t, p = map(int, stdin.readline().split())
    T[i+1] = t
    P[i+1] = p

for i in range(1, N+1):
    dp[i] = max(dp[i], dp[i-1])
    if i + T[i] - 1 <= N:  # 퇴사 전에 상담 완료 가능하면
        dp[i + T[i] - 1] = max(dp[i + T[i] - 1], dp[i - 1] + P[i])

print(max(dp))