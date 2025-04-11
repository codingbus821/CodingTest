import sys
from collections import deque

N, M, K = map(int,sys.stdin.readline().split())

board = []
dy=[0,1,0,-1]
dx=[1,0,-1,0]
p_dy=[1,1,1,0,0,-1,-1,-1]
p_dx=[1,0,-1,1,-1,1,0,-1]

for _ in range(N):
    l = list(map(int,sys.stdin.readline().split()))
    new_list = []
    for i in (l):
        new_list.append([i,0])
    board.append(new_list)

for K_num in range(K):

    # 공격자 선정
    att_w = 0
    att_min = 55555
    att_last = -1
    ijsum = -1
    maxj = -1
    for i in range(N):
        for j in range(M):
            if board[i][j][0] > 0:
                if board[i][j][0] < att_min:
                    att_w = (i,j)
                    att_min = board[i][j][0]
                    att_last = board[i][j][1]
                    ijsum = i+j
                    maxj = j
                elif board[i][j][0] == att_min:
                    if board[i][j][1] > att_last:
                        att_w = (i,j)
                        att_min = board[i][j][0]
                        att_last = board[i][j][1]
                        ijsum = i+j
                        maxj = j
                    elif board[i][j][1] == att_last:
                        if i + j > ijsum:
                            att_w = (i,j)
                            att_min = board[i][j][0]
                            att_last = board[i][j][1]
                            ijsum = i+j
                            maxj = j
                        elif i + j == ijsum:
                            if j > maxj:
                                att_w = (i,j)
                                att_min = board[i][j][0]
                                att_last = board[i][j][1]
                                ijsum = i+j
                                maxj = j
    # print(att_w)
    board[att_w[0]][att_w[1]][0] = board[att_w[0]][att_w[1]][0]+(N+M)
    board[att_w[0]][att_w[1]][1] = K_num+1
    att = att_w

    # 공격자의 공격
    # 가장 강한 포탑 찾기
    
    att_w = 0
    att_max = -1
    att_last = -1
    ijsum = 55555555
    maxj = 5555
    for i in range(N):
        for j in range(M):
            if board[i][j][0] > 0:
                # print(board[i][j][0], att_min)
                if board[i][j][0] > att_max and (i,j) != att:
                    att_w = (i,j)
                    att_max = board[i][j][0]
                    att_last = board[i][j][1]
                    ijsum = i+j
                    maxj = j
                elif board[i][j][0] == att_max:
                    if board[i][j][1] < att_last:
                        att_w = (i,j)
                        att_max = board[i][j][0]
                        att_last = board[i][j][1]
                        ijsum = i+j
                        maxj = j
                    elif board[i][j][1] == att_last:
                        if i + j < ijsum:
                            att_w = (i,j)
                            att_max = board[i][j][0]
                            att_last = board[i][j][1]
                            ijsum = i+j
                            maxj = j
                        elif i + j == ijsum:
                            if j < maxj:
                                att_w = (i,j)
                                att_max = board[i][j][0]
                                att_last = board[i][j][1]
                                ijsum = i+j
                                maxj = j
    
  
    # 레이저 시도                            
 
    de = att_w
    # print(att,de)
    
    visited = [[False] * M for _ in range(N)]
    d = deque()
    d.append((att[0],att[1],[]))
    visited[att[0]][att[1]] = True
    
    razer = False
    razer_list = []
    while d:
        y,x,l = d.popleft()
        
        if (y,x) == de:
            razer = True
            razer_list = l
            break
        for i in range(4):
            # print(y+dy[i])
            ny, nx = (y+dy[i])%N, (x+dx[i])%M
            if board[ny][nx][0] != 0 and visited[ny][nx] == False:
                new_l = l[:]
                new_l.append((ny,nx))
                d.append((ny,nx,new_l))
                visited[ny][nx] = True
    p_list = []
    if razer == True:
        for y,x in razer_list:
            if (y,x) == de:
                board[y][x][0] -= board[att[0]][att[1]][0]
            else:
                board[y][x][0] -= board[att[0]][att[1]][0] // 2 
            if board[y][x][0] < 0:
                board[y][x][0] = 0
    else:
        board[de[0]][de[1]][0] -= board[att[0]][att[1]][0]
        if board[de[0]][de[1]][0] < 0:
            board[de[0]][de[1]][0] = 0
        for i in range(8):
            ny,nx = (de[0]+p_dy[i])%N, (de[1]+p_dx[i])%M
            if (ny,nx) != att:
                p_list.append((ny,nx))
                board[ny][nx][0] -= board[att[0]][att[1]][0] // 2
                if board[ny][nx][0] < 0:
                    board[ny][nx][0] = 0
    
    # print(board)
    
    alive = 0
    for i in range(N):
        for j in range(M):
            if board[i][j][0] > 0: alive+=1
    if alive <= 1:
        break
    broken = []
    # 부서진 포탑 저장
    for i in range(N):
        for j in range(M):
            if board[i][j][0] == 0:
                broken.append((i,j))
    for i in range(N):
        for j in range(M):
            if board[i][j][0] > 0:
                if (i,j) != att and (i,j) != de and (i,j) not in p_list and (i,j) not in razer_list:
            # if (i,j) not in p_list and (i,j) not in razer_list and (i,j) != att and (i,j) != de and (i,j) not in broken:
                    board[i][j][0] += 1
    # print(att,de)
    # print(razer)
    # print(razer_list)
    # print(board)
    
ret = 0
for i in range(N):
    for j in range(M):
        ret = max(ret,board[i][j][0])
print(ret)