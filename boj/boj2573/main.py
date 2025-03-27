import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

board = []
dy = [1,0,-1,0]
dx = [0,1,0,-1]

for _ in range(N):
    s = list(map(int, sys.stdin.readline().split()))
    board.append(s)

cnt = 0

while True:
    visited = [[False]*M for _ in range(N)]
    bing = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] != 0 and visited[i][j] == False:
                q = deque()
                q.append((i,j))
                visited[i][j] = True
                bing += 1
                while q:
                    a, b = q.popleft()
                    for k in range(4):
                        na, nb = a+dy[k], b+dx[k]
                        if 0<=na<N and 0<=nb<M and board[na][nb] != 0 and visited[na][nb] == False:
                            visited[na][nb] = True
                            q.append((na,nb))
    # print(bing)
    if bing >= 2:
        print(cnt)
        break
    elif bing == 0:
        print(0)
        break
    
    m_set = set()
    
    for i in range(N):
        for j in range(M):
            if board[i][j] != 0:
                m_value = 0
                for k in range(4):
                    ni, nj = i+dy[k], j+dx[k]
                    if 0<=ni<N and 0<=nj<M and board[ni][nj] == 0:
                        m_value += 1
                m_set.add((i,j,m_value))
    
    for i,j,m in m_set:
        if board[i][j] - m < 0:
            board[i][j] = 0
        else: board[i][j] -= m
    
    cnt+=1