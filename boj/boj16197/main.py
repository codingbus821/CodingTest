import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

dy=[0,1,0,-1]
dx=[1,0,-1,0]

board = [[] for _ in range(N)]
coin = []
dq = deque()

for i in range(N):
    s = sys.stdin.readline()
    for j in range(len(s)):
        if s[j] == 'o':
            board[i].append(1)
            coin.append([i,j])
        if s[j] == '.':
            board[i].append(0)
        if s[j] == '#':
            board[i].append(2)
coin.append(0)
dq.append(coin)

while dq:
    now = dq.popleft()
    # print(now)
    # print(dq)
    if now[2] >= 10:
        print(-1)
        exit()
    for i in range(4):
        newcoin1 = [now[0][0]+dy[i], now[0][1]+dx[i]]
        newcoin2 = [now[1][0]+dy[i], now[1][1]+dx[i]]
        out = 0
        
        if newcoin1[0]<0 or newcoin1[0]>=N or newcoin1[1] <0 or newcoin1[1]>=M:
            out+=1
        if newcoin2[0]<0 or newcoin2[0]>=N or newcoin2[1] <0 or newcoin2[1]>=M:
            out+=1
        
        if out == 2:
            continue
        if out == 1:
            print(now[2]+1)
            exit()

        if 0<=newcoin1[0]<N and 0<=newcoin1[1]<M:
            if board[newcoin1[0]][newcoin1[1]] == 2:
                newcoin1 = [now[0][0], now[0][1]]
        
        if 0<=newcoin2[0]<N and 0<=newcoin2[1]<M:
            if board[newcoin2[0]][newcoin2[1]] == 2:
                newcoin2 = [now[1][0], now[1][1]]

        if newcoin1[0] == newcoin2[0] and newcoin1[1] == newcoin2[1]:
            continue
        dq.append([newcoin1, newcoin2, now[2]+1])

print(-1)