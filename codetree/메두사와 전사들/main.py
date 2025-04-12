from collections import deque

N, M = map(int, input().split())
sy, sx, ey, ex = map(int, input().split())
m_f_list = list(map(int, input().split()))
m_list = []
board=[]
for i in range(M):
    m_list.append((m_f_list[2*i], m_f_list[2*i+1]))

for _ in range(N):
    board.append(list(map(int, input().split())))

dy=[-1,1,0,0]
dx=[0,0,-1,1]
s_min_list = 0
# print(m_list)

visited = [[False] * N for _ in range(N)]
d = deque()
d.append((sy,sx,[]))
visited[sy][sx] = True

while d:
    y, x, now_list = d.popleft()

    if (y,x) == (ey,ex):
        s_min_list = now_list[:]
    
    for i in range(4):
        ny, nx = y+dy[i], x+dx[i]
        if 0<=ny<N and 0<=nx<N and visited[ny][nx]==False and board[ny][nx] == 0:
            visited[ny][nx] = True
            new_list = now_list[:]
            new_list.append((ny,nx))
            d.append((ny,nx,new_list))

if s_min_list == 0:
    print(-1)
    exit()
ret = 0
for move_y, move_x in s_min_list:
    sy, sx = move_y, move_x # 메두사 이동
    if (sy, sx) == (ey, ex):
        print(0)
        break
    # 전사 공격
    new_m_list = []
    for my, mx in m_list:
        if (my,mx) != (sy,sx):
            new_m_list.append((my,mx))
    m_list = new_m_list[:]
    # 4방향 바라보고 돌로 변신 시킬수있는 전사들 구하기
    # print("here")
    # print(sy,sx)
    max_m = -1
    max_i = -1
    max_stun_list = []
    max_not_move_list = []
    for i in range(4):
        m_num = 0
        stun_list = []
        not_move_list=[]
        if i == 0:
            for j in range(sy-1,-1,-1):
                not_move_list.append((j,sx))
                if (j,sx) in m_list:
                    for _ in range(m_list.count((j,sx))):
                        stun_list.append((j,sx))
                    break
            # print("loop start")
            pass_set1 = set()
            pass_set2 = set()
            for j in range(sy-1,-1,-1):
                p_list = list(pass_set1)
                for p_item in p_list:
                    pass_set1.add(p_item-1)
                for k in range(sx-abs(j-sy),sx):
                    if k in pass_set1:
                        continue
                    not_move_list.append((j,k))
                    if (j,k) in m_list:
                        for _ in range(m_list.count((j,k))):
                            stun_list.append((j,k))
                        pass_set1.add(k)
                p_list = list(pass_set2)
                for p_item in p_list:
                    pass_set2.add(p_item+1)
                for k in range(sx+1,sx+abs(j-sy)+1):
                    if k in pass_set2:
                        continue
                    not_move_list.append((j,k))
                    if (j,k) in m_list:
                        for _ in range(m_list.count((j,k))):
                            stun_list.append((j,k))
                        pass_set2.add(k)
            # print(stun_list)
        if i == 2:
            # print(m_list)
            for j in range(sx-1,-1,-1):
                not_move_list.append((sy,j))
                if (sy,j) in m_list:
                    for _ in range(m_list.count((sy,j))):
                        stun_list.append((sy,j))
                    break
            pass_set1 = set()
            pass_set2 = set()
            for j in range(sx-1,-1,-1):
                p_list = list(pass_set1)
                for p_item in p_list:
                    pass_set1.add(p_item-1)
                for k in range(sy-abs(j-sx),sy):
                    if k in pass_set1:
                        continue
                    not_move_list.append((k,j))
                    if (k,j) in m_list:
                        for _ in range(m_list.count((k,j))):
                            stun_list.append((k,j))
                        pass_set1.add(k)
                p_list = list(pass_set2)
                for p_item in p_list:
                    pass_set2.add(p_item+1)
                for k in range(sy+1,sy+abs(j-sx)+1):
                    if k in pass_set2:
                        continue
                    not_move_list.append((k,j))
                    if (k,j) in m_list:
                        for _ in range(m_list.count((k,j))):
                            stun_list.append((k,j))
                        pass_set2.add(k)
            # print(stun_list)
        
        if i == 3:
            # print(m_list)
            for j in range(sx+1,N):
                not_move_list.append((sy,j))
                if (sy,j) in m_list:
                    for _ in range(m_list.count((sy,j))):
                        stun_list.append((sy,j))
                    break
            pass_set1 = set()
            pass_set2 = set()
            for j in range(sx+1,N):
                p_list = list(pass_set1)
                for p_item in p_list:
                    pass_set1.add(p_item-1)
                for k in range(sy-abs(j-sx),sy):
                    if k in pass_set1:
                        continue
                    not_move_list.append((k,j))
                    if (k,j) in m_list:
                        for _ in range(m_list.count((k,j))):
                            stun_list.append((k,j))
                        pass_set1.add(k)
                p_list = list(pass_set2)
                for p_item in p_list:
                    pass_set2.add(p_item+1)
                for k in range(sy+1,sy+abs(j-sx)+1):
                    if k in pass_set2:
                        continue
                    not_move_list.append((k,j))
                    if (k,j) in m_list:
                        for _ in range(m_list.count((k,j))):
                            stun_list.append((k,j))
                        pass_set2.add(k)
            # print(stun_list)    
        
        if i == 1:
            for j in range(sy+1,N):
                not_move_list.append((j,sx))
                if (j,sx) in m_list:
                    for _ in range(m_list.count((j,sx))):
                        stun_list.append((j,sx))
                    break
            pass_set1 = set()
            pass_set2 = set()
            for j in range(sy+1,N):
                p_list = list(pass_set1)
                for p_item in p_list:
                    pass_set1.add(p_item-1)
                for k in range(sx-abs(j-sy),sx):
                    if k in pass_set1:
                        continue
                    not_move_list.append((j,k))
                    if (j,k) in m_list:
                        for _ in range(m_list.count((j,k))):
                            stun_list.append((j,k))
                        pass_set1.add(k)
                p_list = list(pass_set2)
                for p_item in p_list:
                    pass_set2.add(p_item+1)
                for k in range(sx+1,sx+abs(j-sy)+1):
                    if k in pass_set2:
                        continue
                    not_move_list.append((j,k))
                    if (j,k) in m_list:
                        for _ in range(m_list.count((j,k))):
                            stun_list.append((j,k))
                        pass_set2.add(k)
            # print(stun_list)            
        
        if len(stun_list) > max_m:
            max_i = i
            max_m = len(stun_list)
            max_stun_list = stun_list[:]
            max_not_move_list = not_move_list[:]
    # print(max_i)
    # print()
    # 전사 이동
    ret1 = 0
    ret3 = 0
    new_m_list = []
    # print(m_list)
    # print(max_stun_list)
    # print(max_not_move_list)
    for my, mx in m_list:
        if (my, mx) not in max_stun_list:
            new_my, new_mx = my, mx
            # print("start")
            # print(new_my,new_mx)
            for move_i in range(2):
                if move_i == 0:
                    max_i = -1
                    min_len = abs(new_my-sy) + abs(new_mx-sx)
                    for k in range(4):
                        ny, nx = new_my+dy[k], new_mx+dx[k]
                        if 0<=ny<N and 0<=nx<N and (ny,nx) not in max_not_move_list and abs(ny-sy) + abs(nx-sx) < min_len:
                            min_len = abs(ny-sy) + abs(nx-sx)
                            max_i = k
                    if max_i != -1:
                        new_my, new_mx = new_my+dy[max_i], new_mx+dx[max_i]
                        ret1 += 1
                    # print(new_my,new_mx)
                    if (new_my, new_mx) == (sy, sx): 
                        ret3 += 1
                        break
                else:
                    max_i = -1
                    min_len = abs(new_my-sy) + abs(new_mx-sx)
                    for k in range(4):
                        ny, nx = new_my+dy[(k+2)%4], new_mx+dx[(k+2)%4]
                        if 0<=ny<N and 0<=nx<N and (ny,nx) not in max_not_move_list and abs(ny-sy) + abs(nx-sx) < min_len:
                            min_len = abs(ny-sy) + abs(nx-sx)
                            max_i = k
                    if max_i != -1:
                        new_my, new_mx = new_my+dy[(max_i+2)%4], new_mx+dx[(max_i+2)%4]
                        ret1 += 1
                    # print(max_i)
                    # print(new_my,new_mx)
                    if (new_my, new_mx) == (sy, sx): 
                        ret3 += 1
                        break
                
            new_m_list.append((new_my,new_mx))
    # print(new_m_list)
    
    last_new_m_list = []
    for my, mx in m_list:
        if (my,mx) in max_stun_list:
            last_new_m_list.append((my,mx))
            # print(my,mx)
    for my, mx in new_m_list:
        if (my,mx) != (sy,sx):
            last_new_m_list.append((my,mx))
    # print(last_new_m_list)
    m_list = last_new_m_list[:]
                
                
        
        
        
    # print(max_i, max_stun_list, max_not_move_list)
    # ret += len(max_stun_list)
    print(ret1, len(max_stun_list), ret3)

# print(ret)

