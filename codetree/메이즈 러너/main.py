import sys

N,M,K = map(int,sys.stdin.readline().split())

board = []
dy=[-1,1,0,0]
dx=[0,0,-1,1]
M_list = []

for _ in range(N):
    board.append(list(map(int,sys.stdin.readline().split())))

for _ in range(M):
    f,s = map(int,sys.stdin.readline().split())
    M_list.append((f-1,s-1))

f,s = map(int,sys.stdin.readline().split())
exit = (f-1,s-1)

# print(board)
# print(M_list)

ret = 0
for _ in range(K):
    
    if len(M_list) == 0: break
    # 참가자 이동
    new_M_list = []
    for y,x in M_list:
        now_len = abs(exit[0]-y)+abs(exit[1]-x)
        next_y, next_x = y,x
        for d in range(4):
            ny,nx = y+dy[d], x+dx[d]
            if 0<=ny<N and 0<=nx<N and board[ny][nx] == 0:
                if (ny,nx) == exit:
                    ret += 1
                    break
                if abs(exit[0]-ny)+abs(exit[1]-nx) < now_len:
                    now_len = abs(exit[0]-ny)+abs(exit[1]-nx)
                    next_y, next_x = ny, nx
                    ret += 1
        else:
            new_M_list.append((next_y,next_x))
    if len(new_M_list) == 0:
        break
    M_list = new_M_list[:]
    
    # print(M_list)
    # print(exit)
    
    # 미로 회전
    chk = False
    last_y, last_x, last_size = 0,0,0
    for size in range(2,N+1): # 2~N
        for i in range(N-1): # 0 ~ N-2
            for j in range(N-1): # 0 ~ N-2
                # print(i,j,size)
                if i<=exit[0]<i+size and j<=exit[1]<j+size:
                    # print("here2")
                    for y,x in M_list:
                        if i<=y<i+size and j<=x<j+size:
                            # print("here",i,j,size)
                            last_y, last_x, last_size = i, j, size
                            chk = True
                            break
                    if chk == True:
                        break
                if chk == True:
                    break
            if chk == True:
                break
        if chk == True:
            break
    # print(last_y, last_x, last_size)

    mini_board = []
    for i in range(last_y,last_y+size):
        mini_board.append(board[i][last_x:last_x+size])
    
    # print(mini_board)
    
    remove_list = []
    new_M_list=[]
    y_cnt = 0
    exit_chk = False
    for i in range(last_y,last_y+size):
        x_cnt = last_size-1
        for j in range(last_x,last_x+size):
            # print(i,j)
            # print(y_cnt,x_cnt)
            board[i][j] = mini_board[x_cnt][y_cnt]
            
            if exit == (x_cnt+last_y,y_cnt+last_x) and exit_chk == False:
                exit_chk = True
                exit = (i,j)
            
            for y,x in M_list:
                next_y, next_x = y,x
                if (y,x) == (x_cnt+last_y,y_cnt+last_x):
                    next_y, next_x = i,j
                    remove_list.append((y,x))
                    new_M_list.append((next_y, next_x))
                #     continue
                # if (next_y, next_x) not in new_M_list:
                #     new_M_list.append((next_y, next_x))
            x_cnt -= 1
        y_cnt += 1
    # print(new_M_list)
    # print(remove_list)
    # print(M_list)
    for y,x in remove_list:
        if (y,x) in M_list:
            M_list.remove((y,x))
    M_list += new_M_list
    # print(M_list)
    # print(board)
    # print(exit)
    
    for i in range(last_y,last_y+size):
        for j in range(last_x,last_x+size):
            if board[i][j] > 0:
                board[i][j] -= 1
    # print(board)
    # print(M_list)
    # print(exit)
    # break
    
print(ret)
print(exit[0]+1, exit[1]+1)