import sys
from collections import deque

dy=[0,1,0,-1]
dx=[1,0,-1,0]

N, M = map(int, sys.stdin.readline().split())

board = [[] for _ in range(N)]
coin = []

for i in range(N):
    s = sys.stdin.readline().strip()
    for j in range(len(s)):
        board[i].append(s[j])
        if s[j] == 'o':
            coin.append(i)
            coin.append(j)
visited = set()
visited.add((coin[0],coin[1],coin[2],coin[3]))
coin.append(0)
d = deque()
d.append(coin)



while d:
    y1, x1, y2, x2, cnt = d.popleft()
    
    if cnt >= 10:
        print(-1)
        exit()
    
    for i in range(4):
        out = 0
        newy1 = y1+dy[i]
        newx1 = x1+dx[i]
        newy2 = y2+dy[i]
        newx2 = x2+dx[i]
        
        chk1 = (0<=newy1<N and 0<=newx1<M)
        chk2 = (0<=newy2<N and 0<=newx2<M)
        
        if not chk1:
            out+=1
        if not chk2:
            out+=1
        
        if out == 2:
            continue
        if out == 1:
            print(cnt+1)
            exit(0)
        
        if board[newy1][newx1] == '#':
            newy1, newx1 = y1, x1
        if board[newy2][newx2] == '#':
            newy2, newx2 = y2, x2
        
        if newy1 == newy2 and newx1 == newx2:
            continue
        
        if (newy1,newx1,newy2,newx2) in visited:
            continue
        
        d.append([newy1,newx1,newy2,newx2,cnt+1])

print(-1)