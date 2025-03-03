import sys
from collections import deque

N, M, K = map(int, sys.stdin.readline().split())

board = [list(input()) for _ in range(N)]

dx = [0,1,0,-1]
dy = [1,0,-1,0]

x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
x1 -= 1
y1 -= 1
x2 -= 1
y2 -= 1

d = deque()
d.append((x1, y1))
board[x1][y1] = 0

while d:
    nowx, nowy = d.popleft()
    
    if nowx == x2 and nowy == y2:
        print(board[x2][y2])
        exit()
    
    for i in range(4):
        for j in range(1,K+1):
            newx = nowx+dx[i]*j
            newy = nowy+dy[i]*j
            
            if 0<=newx<N and 0<=newy<M:
                if board[newx][newy] == '#':
                    break
                else:
                    if board[newx][newy] == '.':
                        board[newx][newy] = board[nowx][nowy] + 1
                        d.append((newx,newy))
                    elif board[newx][newy] > board[nowx][nowy]: continue
                    else: break
            else:
                break

print(-1)