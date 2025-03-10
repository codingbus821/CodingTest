from collections import deque
import sys

dy = [1,0,-1,0]
dx = [0,1,0,-1]

N, M, K = map(int, sys.stdin.readline().split())

board = [list(sys.stdin.readline().strip()) for _ in range(N)]
dp = [[0] * M for _ in range(N)]
    
x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

if x1 == x2 and y1 == y2:
    print(0)
    exit()
    
d = deque()
d.append((x1-1,y1-1))
board[x1-1][y1-1] = 0

while d:
    x, y = d.popleft()
    for i in range(4):
        for k in range(K):
            newx, newy = x+dx[i]*(k+1), y+dy[i]*(k+1)
            
            if not 0<=newx<N or not 0<=newy<M or board[newx][newy] == '#':
                break
            if board[newx][newy] == '.':
                board[newx][newy] = board[x][y] + 1
                d.append((newx,newy))
            elif board[newx][newy] <= board[x][y]:
                break
            # else: break
                
if board[x2-1][y2-1] == '.':
    print(-1)
else:
    print(board[x2-1][y2-1])