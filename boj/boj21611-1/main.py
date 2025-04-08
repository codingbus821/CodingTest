import sys
from collections import deque
import copy

N, M = map(int, sys.stdin.readline().split())

board = []

dy=[0,-1,1,0,0]
dx=[0,0,0,-1,1]

c = (int((N+1)/2-1),int((N+1)/2-1))

for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().split())))

# print(board[c[0]][c[1]])

to_idx = {}

d = deque()

d.append((c,3,0,1)) # 지금위치, 방향, 현재간횟수, 최종가는횟수
ball_list=[]
ball_list.append(0)
idx = 0

while d:
    now, dir, now_num, last_num = d.popleft()
    to_idx[now] = idx
    idx += 1
    # print(now)
    ny, nx = now[0]+dy[dir], now[1]+dx[dir]
    if 0<=ny<N and 0<=nx<N:
        ball_list.append(board[ny][nx])
        if now_num+1 == last_num:
            if dir == 3:
                nd = 2
            elif dir == 2:
                nd = 4
            elif dir == 4:
                nd = 1
            else:
                nd = 3
            now_num = -1
        if ny+nx == N-1:
            last_num += 1
        d.append(((ny,nx),nd,now_num+1,last_num))

ret = 0

for _ in range(M):
    d, s_len = map(int, sys.stdin.readline().split())
    
    # 구슬 삭제
    # if d == 3:
    #     start = 1
    #     f,s,t = 3,4,1
    # if d == 2:
    #     start = 3
    #     f,s,t = 3,4,2
    # if d == 4:
    #     start = 5
    #     f,s,t = 4,5,2
    # if d == 1:
    #     start = 7
    #     f,s,t = 4,5,3
    # ball_list[start] = 0
    
    for s_num in range(s_len):
        ny, nx = c[0] + (s_num+1)*dy[d], c[1] + (s_num+1)*dx[d]
        
        if (ny,nx) in to_idx:
            idx = to_idx[(ny,nx)]
            if idx < len(ball_list):
                ball_list[idx] = 0

    # print(ball_list)
        
        # if len(ball_list) > start+f+s+t+t:
        #     ball_list[start+f+s+t+t] = 0
        #     start = start+f+s+t+t
        #     f+=1
        #     s+=1
        #     t+=2
    
    # 구슬 이동
    new_list = [0]
    for i in ball_list:
        if i != 0:
            new_list.append(i)
    
    # print(new_list)
    # 폭발
    while True:
        ex = -1
        dup = 0
        zero_list = []
        for i in range(len(new_list)):
            # print(i)
            if new_list[i] == ex:
                dup += 1
            if new_list[i] != ex:
                if dup >= 4:
                    # print("here")
                    # print(ex,dup)
                    for j in range(dup):
                        zero_list.append(i-j-1)
                dup = 1
            ex = new_list[i]        
        if dup >= 4:
            # print("here")
            # print(ex,dup)
            for j in range(dup):
                zero_list.append(len(new_list)-j-1)
        # print(zero_list)
        # break
        for ze in zero_list:
            ret += new_list[ze]
            new_list[ze] = 0
        new_new_list = [0]
        for new in new_list:
            if new != 0:
                new_new_list.append(new)
        new_list = new_new_list[:]
        if len(zero_list) == 0: break
    
    # print(new_list)
    
    # print(new_list)
    
    # 구슬 변화
    new_new_list = [0]
    if len(new_list) > 2:
        ex = new_list[1]
    else:
        ex = 0
    dup = 0
    for i in range(1,len(new_list)):
        if new_list[i] == ex:
            dup += 1
        if new_list[i] != ex:
            if len(new_new_list) < N*N:
                new_new_list.append(dup)
            else:
                break
            if len(new_new_list) < N*N:
                new_new_list.append(ex)
            else:break
            dup = 1
        ex = new_list[i]
    if len(new_new_list) < N*N:
        new_new_list.append(dup)
    if len(new_new_list) < N*N:
        new_new_list.append(ex)
    # print(new_new_list)
    
    ball_list = new_new_list[:]
    
print(ret)