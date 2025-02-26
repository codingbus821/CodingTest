from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())

board = []
ret = 0

dy = [-1,-1,-1,0,1,1,1,0]
dx = [-1,0,1,1,1,0,-1,-1]

for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

d = deque()

for i in range(N):
    for j in range(M):
        if board[i][j] == 1:
            d.append([i,j])

while d:
    f, s = d.popleft()
    for k in range(8):
        newi, newj = f+dy[k], s+dx[k]
        if 0 <= newi < N and 0 <= newj < M and board[newi][newj] == 0:
            d.append([newi, newj])
            board[newi][newj] = board[f][s] + 1

for i in range(N):
    for j in range(M):
        ret = max(ret, board[i][j])

print(ret-1)