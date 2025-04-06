import sys
from collections import deque
import copy

M, S = map(int, sys.stdin.readline().split())

fish = [[[] for _ in range(5)] for _ in range(5)]
smell_board = [[0]*5 for _ in range(5)]

fish_dy=[0,0,-1,-1,-1,0,1,1,1]
fish_dx=[0,-1,-1,0,1,1,1,0,-1]
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
                for k in range(d, d-8, -1):
                    k = k % 8
                    ny,nx = i+fish_dy[k], j+fish_dx[k]
                    if 1<=nx<=4 and 1<=ny<=4 and (ny,nx) != (sy,sx) and smell_board[ny][nx] == 0:
                        ret[ny][nx].append(k)
                        break
                else:
                    ret[i][j].append(d)
    return ret


def dfs(y,x,m_cnt,total,visit):
    
    global m_m_list, m_total,sy,sx
    
    if m_cnt == 3:
        if total > m_total:
            m_total = total
            m_m_list = visit[:]
        return
    
    for i in range(4):
        ny,nx = y+s_dy[i], x+s_dx[i]
        if 1<=nx<=4 and 1<=ny<=4:
            if (ny,nx) not in visit:
                visit.append((ny,nx))
                dfs(ny,nx,m_cnt+1,total+len(tmp[ny][nx]),visit)
                visit.pop()
            else:
                dfs(ny,nx,m_cnt+1,total,visit)
        

for i in range(S):
    m_total = -1
    m_m_list = list()
    # print(i,"----------")
    tmp = copy.deepcopy(fish)
    tmp = move(tmp)
    dfs(sy,sx,0,0,list())
    for y,x in m_m_list:
        sy, sx = y, x
        if tmp[y][x]:
            tmp[y][x] = []
            smell_board[y][x] = 3
    # print(tmp)

    for i in range(1,5):
        for j in range(1,5):
            if smell_board[i][j] > 0:
                smell_board[i][j] -= 1
    for i in range(1,5):
        for j in range(1,5):
            fish[i][j] += tmp[i][j]
    # fish = copy.deepcopy(tmp)
    # print(fish)

answer = 0
for i in range(1,5):
    for j in range(1,5):
        answer += len(fish[i][j])

print(answer)