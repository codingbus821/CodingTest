import sys
from collections import deque
import copy

N, M = map(int, sys.stdin.readline().split())
board = []
wall=[]
virus=[]
dy=[0,1,0,-1]
dx=[1,0,-1,0]
ret = 0

for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

for i in range(N):
    for j in range(M):
        if board[i][j] == 0:
            wall.append((i,j))
        elif board[i][j] == 2:
            virus.append((i,j))

for i in range(len(wall)):
    for j in range(i+1,len(wall)):
        for k in range(j+1,len(wall)):
            board[wall[i][0]][wall[i][1]] = 1
            board[wall[j][0]][wall[j][1]] = 1
            board[wall[k][0]][wall[k][1]] = 1
            
            new_board = copy.deepcopy(board)
            
            visited = []
            for _ in range(N):
                visited.append([False]*M)
            
            d = deque()
            
            for a,b in virus:
                visited[a][b] = True
                d.append((a,b))
            
            while d:
                a,b = d.popleft()
                for di in range(4):
                    newa, newb = a+dy[di], b+dx[di]
                    if 0<=newa<N and 0<=newb<M and visited[newa][newb] == False and new_board[newa][newb] == 0:
                        visited[newa][newb] = True
                        new_board[newa][newb] = 2
                        d.append((newa,newb))
            
            cnt = 0
            
            for c in range(N):
                for d in range(M):
                    if new_board[c][d] == 0:
                        cnt += 1
            
            ret = max(ret, cnt)
                
            board[wall[i][0]][wall[i][1]] = 0
            board[wall[j][0]][wall[j][1]] = 0
            board[wall[k][0]][wall[k][1]] = 0

print(ret)