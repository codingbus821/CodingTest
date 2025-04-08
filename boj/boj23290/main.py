import sys
from collections import deque
import copy

M, S = map(int, sys.stdin.readline().split())

fish = [[[] for _ in range(5)] for _ in range(5)]
smell_board = [[0]*5 for _ in range(5)]

fish_dx = [0, -1, -1, 0, 1, 1, 1, 0, -1]
fish_dy = [0, 0, -1, -1, -1, 0, 1, 1, 1]

s_dy=[-1,0,1,0]
s_dx=[0,-1,0,1]

for _ in range(M):
    y,x,d = map(int, sys.stdin.readline().split())
    # fish.append((y,x,d))
    fish[y][x].append(d)
    # fish_to_num[(y,x)] += 1

sy, sx = map(int, sys.stdin.readline().split())

def move(tmp):
    # global tmp
    ret = [[[] for _ in range(5)] for _ in range(5)]
    for i in range(1,5):
        for j in range(1,5):
            while tmp[i][j]:
                d = tmp[i][j].pop()
                for k in range(8):
                    nd = (d - k - 1) % 8 + 1
                    ny,nx = i+fish_dy[nd], j+fish_dx[nd]
                    if 1<=nx<=4 and 1<=ny<=4 and (ny,nx) != (sy,sx) and smell_board[ny][nx] == 0:
                        ret[ny][nx].append(nd)
                        break
                else:
                    ret[i][j].append(d)
    return ret


def dfs(y,x,m_cnt,total,visit,tmp):
    
    global m_total, m_m_list,sy,sx
    if m_cnt == 3:
        if total > m_total:
            sy,sx = y,x
            m_total = total
            m_m_list = visit[:]
        return
    
    for i in range(4):
        ny,nx = y+s_dy[i], x+s_dx[i]
        if 1<=nx<=4 and 1<=ny<=4:
            if (ny,nx) not in visit:
                visit.append((ny,nx))
                dfs(ny,nx,m_cnt+1,total+len(tmp[ny][nx]),visit,tmp)
                visit.pop()
            else:
                dfs(ny,nx,m_cnt+1,total,visit,tmp)
        

for i in range(S):
    m_total = -1
    m_m_list = list()
    # print(i,"----------")
    backup = copy.deepcopy(fish)        # Step 1: backup for copy
    tmp = move(copy.deepcopy(fish))     # Step 2: move
    dfs(sy,sx,0,0,list(),tmp)
    for y,x in m_m_list:
        # sy, sx = y, x
        if tmp[y][x]:
            tmp[y][x] = []
            smell_board[y][x] = 3
    # print(tmp)

    for i in range(1,5):
        for j in range(1,5):
            if smell_board[i][j] > 0:
                smell_board[i][j] -= 1
    for i in range(1, 5):
        for j in range(1, 5):
            fish[i][j] = tmp[i][j][:]
    for i in range(1, 5):
        for j in range(1, 5):
            fish[i][j].extend(backup[i][j])
    # fish = copy.deepcopy(tmp)
    # print(fish)

answer = 0
for i in range(1,5):
    for j in range(1,5):
        answer += len(fish[i][j])

print(answer)