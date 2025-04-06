import sys
from collections import deque

M, S = map(int, sys.stdin.readline().split())

fish = []
fish_to_num = {}
smell_board = [[0]*5 for _ in range(5)]

fish_dy=[0,0,-1,-1,-1,0,1,1,1]
fish_dx=[0,-1,-1,0,1,1,1,0,-1]
s_dy=[-1,0,1,0]
s_dx=[0,-1,0,1]

for i in range(1,5):
        for j in range(1,5):
            fish_to_num[(i,j)] = 0

for _ in range(M):
    y,x,d = map(int, sys.stdin.readline().split())
    fish.append((y,x,d))
    fish_to_num[(y,x)] += 1

sy, sx = map(int, sys.stdin.readline().split())

def move():
    global fish
    new_fish = []
    print(fish)
    for y,x,d in fish:
        chk = False
        # print("before",y,x)
        for i in range(d,0,-1):
            # print(i,fish_dy[i],fish_dx[i])
            ny,nx = y+fish_dy[i], x+fish_dx[i]
            # print(ny,nx)
            if 1<=nx<=4 and 1<=ny<=4 and (nx != sx or ny != sy) and smell_board[ny][nx] == 0:
                new_fish.append((ny,nx,i))
                fish_to_num[(y,x)] -= 1   
                fish_to_num[(ny,nx)] += 1
                chk = True
                # print("after",ny,nx)
                # print("append")
                break
        chk2 = False
        if chk == False:
            # print("false")
            for i in range(8,d,-1):
                # print(i,fish_dy[i],fish_dx[i])
                ny,nx = y+fish_dy[i], x+fish_dx[i]
                # print(ny,nx)
                if 1<=nx<=4 and 1<=ny<=4 and (nx != sx or ny != sy) and smell_board[ny][nx] == 0:
                    new_fish.append((ny,nx,i))
                    fish_to_num[(y,x)] -= 1
                    fish_to_num[(ny,nx)] += 1
                    # print("append")
                    # print("after",ny,nx)
                    chk2 = True
                    break
        if chk2 == False and chk == False:
            new_fish.append((y,x,d))
    fish = new_fish[:]
    print(fish)

def dfs(y,x,m_cnt,total,m_list):
    
    global m_m_list, m_total, visited
    
    if m_cnt == 3:
        if total > m_total:
            m_total = total
            m_m_list = m_list
            # print(y,x,m_cnt,total,m_list)
        return
    
    for i in range(4):
        ny,nx = y+s_dy[i], x+s_dx[i]
        if 1<=nx<=4 and 1<=ny<=4 and visited[ny][nx] == False:
            visited[ny][nx] = True
            new_list = m_list[:]
            new_list.append(i)
            if (ny,nx) in fish_to_num:
                dfs(ny,nx,m_cnt+1,total+fish_to_num[(ny,nx)],new_list)
            else:
                dfs(ny,nx,m_cnt+1,total,new_list)
            visited[ny][nx] = False
        

def s_move():
    global sy, sx


    # print("s_move")
    # print(sy,sx)
    
    dfs(sy,sx,0,0,[])
    
    # while q:
    #     y,x,m_cnt,total,m_list = q.popleft()
        
    #     if m_cnt == 3:
    #         if total > m_total:
    #             m_total = total
    #             m_m_list = m_list
    #         print(y,x,m_cnt,total,m_list)
    #         continue
        
    #     for i in range(4):
    #         ny,nx = y+s_dy[i], x+s_dx[i]
    #         if 1<=nx<=4 and 1<=ny<=4 and visited[ny][nx] == False:
    #             visited[ny][nx] = True
    #             new_list = m_list[:]
    #             new_list.append(i)
    #             if (ny,nx) in fish_to_num:
    #                 q.append((ny,nx,m_cnt+1,total+fish_to_num[(ny,nx)],new_list))
    #             else:
    #                 q.append((ny,nx,m_cnt+1,total,new_list))
    # print(m_m_list)
    

for i in range(S):
    print(i,"----------")
    copy_fish = fish[:]
    print("before",len(fish))
    move()
    # print(sy,sx)
    visited = [[False] * 5 for _ in range(5)]
    m_total = -1
    m_m_list = []
    s_move()
    # print(m_m_list)
    for i in m_m_list:
        # print(i)
        sy, sx = sy+s_dy[i], sx+s_dx[i]
        # print(sy,sx)
        if fish_to_num[(sy,sx)] > 0:
            fish_to_num[(sy,sx)] = 0
            smell_board[sy][sx] = 3
            for j in range(1,9):
                if (sy,sx,j) in fish:
                    fish.remove((sy,sx,j))
    for i in range(1,5):
        for j in range(1,5):
            if smell_board[i][j] > 0:
                smell_board[i][j] -= 1
    for y,x,d in copy_fish:
        fish.append((y,x,d))
        fish_to_num[(y,x)] += 1
    # print(fish)
    # print(fish_to_num)
    # print(smell_board)
    # print(fish)
    sum = 0
    # print(fish_to_num)
    for val in fish_to_num.values():
        # print(val)
        sum += val
    print(sum)