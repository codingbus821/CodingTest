import sys
from collections import deque

M, N, H = map(int, sys.stdin.readline().split())

dy=[0,1,0,-1,0,0]
dx=[1,0,-1,0,0,0]
dh=[0,0,0,0,1,-1]

box_list = []
d = deque()
s = set()
empty = 0

for i in range(H):
    tmp = []
    for j in range(N):
        l = list(map(int, sys.stdin.readline().split()))
        tmp.append(l)
        for k in range(len(l)):
            if l[k] == 1:
                s.add((k,j,i))
                d.append((k,j,i,0))
            if l[k] == -1:
                empty+=1
    box_list.append(tmp)

# print(box_list[1][1][2])
# print(d)
# print(len(box_list))
last_day = 0
while d:
    k,j,i,day = d.popleft()
    last_day = day
    for di in range(6):
        nk, nj, ni = k+dx[di], j+dy[di], i+dh[di]
        # print(ni,nj,nk)
        if 0<=nk<M and 0<=nj<N and 0<=ni<H and box_list[ni][nj][nk] == 0:
            # print(ni,nj,nk)
            box_list[ni][nj][nk] = 1
            s.add((nk,nj,ni))
            d.append((nk,nj,ni,day+1))

# for i in range(H):
#     for j in range(N):
#         for k in range(M):
#             print(box_list[i][j][k], end="")
#         print()
#     print()

if len(s) == M*N*H - empty:
    print(last_day)
else: print(-1)
        