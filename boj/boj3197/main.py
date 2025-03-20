import sys
from collections import deque

R, C = map(int, sys.stdin.readline().split())

board = []
dest = []
dy=[1,0,-1,0]
dx=[0,1,0,-1]

for _ in range(R):
    board.append(list(sys.stdin.readline().strip()))
melt_next_q = deque()
for i in range(R):
    for j in range(C):
        if board[i][j] == 'L':
            dest.append((i,j))
            board[i][j] = '.'
        if board[i][j] == '.':
            melt_next_q.append((i,j))

ans = 0

next_q = deque()
next_q.append((dest[0][0], dest[0][1]))
visited = [[False] * C for _ in range(R)]
visited[dest[0][0]][dest[0][1]] = True

while True:
    d = next_q
    next_q = deque()
    while d:
        a, b = d.popleft()
        if a == dest[1][0] and b == dest[1][1]:
            print(ans)
            exit()
        for i in range(4):
            newa, newb = a+dy[i], b+dx[i]
            if not (0<=newa<R and 0<=newb<C):
                continue
            if visited[newa][newb] == True:
                continue
            if board[newa][newb] == 'X':
                visited[newa][newb] = True
                next_q.append((newa,newb))
                continue
            visited[newa][newb] = True
            d.append((newa,newb))

    
    melt_q = melt_next_q
    melt_next_q = deque()
    
    while melt_q:
        a, b = melt_q.popleft()
        for i in range(4):
            newa, newb = a+dy[i], b+dx[i]
            if not (0<=newa<R and 0<=newb<C):
                continue
            if board[newa][newb] == 'X':
                board[newa][newb] = '.'
                melt_next_q.append((newa,newb))
    
    ans += 1