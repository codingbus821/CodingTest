import sys
from collections import deque

miji_board = []
dong = []
seo =[]
nam = []
buk = []
top = []
isang = []
dy=[0,0,1,-1,0]
dx=[1,-1,0,0,0]


#--- 입력 받는 부분

N, M, F = map(int, sys.stdin.readline().split())

for _ in range(N):
    miji_board.append(list(map(int, sys.stdin.readline().split())))

for i in range(5):
    for _ in range(M):
        if i == 0:
            dong.append(list(map(int, sys.stdin.readline().split())))
        elif i == 1:
            seo.append(list(map(int, sys.stdin.readline().split())))
        elif i == 2:
            nam.append(list(map(int, sys.stdin.readline().split())))
        elif i == 3:
            buk.append(list(map(int, sys.stdin.readline().split())))
        else:
            top.append(list(map(int, sys.stdin.readline().split())))

for _ in range(F):
    s = list(map(int, sys.stdin.readline().split()))
    s.append("miji")
    isang.append(s)

#-----

#----초기세팅

for i in isang:
    miji_board[i[0]][i[1]] = 5

q = deque()

for i in range(M):
    for j in range(M):
        if top[i][j] == 2:
            q.append(['top',i,j,0])
            break
    if q:
        break

# print(q)

s_p = 0

for i in range(N):
    for j in range(N):
        if miji_board[i][j] == 3:
            s_p = [i,j]
            break
    if s_p != 0:
        break

#----

#--- go 함수 구현
def go(where, i, j, direction, isang = False):
    next_i, next_j = i+dy[direction], j+dx[direction]
    if where == 'miji': # 미지의 공간일 경우
        if 0<=next_i<N and 0<=next_j<N:
            if miji_board[next_i][next_j] == 0: # 미지의 공간의 빈칸일 경우
                miji_board[next_i][next_j] = 1
                return (('miji',next_i,next_j,direction))
            elif miji_board[next_i][next_j] == 3: # 미지의 공간에서 시간의 벽으로 이동
                if direction == 0 and 0<=next_i-s_p[0]<M and 0<=M-1: #동쪽 방향으로 이동
                    return go('seo',M-1,next_i-s_p[0],direction)
                elif direction == 1 and 0<=next_i-s_p[0]<M and 0<=M-1:#서
                    return go('dong',M-1,next_i-s_p[0],direction)
                elif direction == 2 and 0<=next_j-s_p[1]<M and 0<=M-1:#남
                    return go('buk',M-1,next_j - s_p[1],direction)
                elif direction == 3 and 0<=next_j-s_p[1]<M and 0<=M-1:
                    return go('nam',M-1,next_j - s_p[1],direction)
            elif miji_board[next_i][next_j] == 4:
                return 9
        else:
            return False
    else: # 미지의 공간이 아닐 경우
        if 0<=next_i<M and 0<=next_j<M:
            if where == 'dong' and dong[next_i][next_j] == 0:
                dong[next_i][next_j] = 1
                return (('dong',next_i,next_j,direction))
            elif where == 'seo' and seo[next_i][next_j] == 0:
                seo[next_i][next_j] = 1
                return (('seo',next_i,next_j,direction))
            elif where == 'nam' and nam[next_i][next_j] == 0:
                nam[next_i][next_j] = 1
                return (('nam',next_i,next_j,direction))
            elif where == 'buk' and buk[next_i][next_j] == 0:
                buk[next_i][next_j] = 1
                return (('buk',next_i,next_j,direction))
            elif where == 'top' and top[next_i][next_j] == 0:
                top[next_i][next_j] = 1
                return (('top',next_i,next_j,direction))
            return False
        elif next_j < 0:
            if where == 'seo' and 0<=next_i<M and 0<=M-1:
                return go('buk',next_i,M-1,4)
            elif where == 'top' and 0<=next_i<M:
                return go('seo',0,next_i,4)
            elif where == 'dong' and 0<=next_i<M and 0<=M-1:
                return go('nam',next_i,M-1,4)
            elif where == 'buk' and 0<=next_i<M and 0<=M-1:
                return go('dong',next_i,M-1,4)
            elif where == 'nam' and 0<=next_i<M and 0<=M-1:
                return go('seo',next_i,M-1,4)
        elif next_j >= M:
            if where == 'seo' and 0<=next_i<M:
                return go('nam',next_i,0,4)
            elif where == 'top' and 0<=M-1-next_i<M:
                return go('dong',0,M-1-next_i,4)
            elif where == 'dong' and 0<=next_i<M:
                return go('buk',next_i,0,4)
            elif where == 'buk' and 0<=next_i<M:
                return go('seo',next_i,0,4)
            elif where == 'nam' and 0<=next_i<M:
                return go('dong',next_i,0,4)
        elif next_i <0 :
            if where == 'seo' and 0<=next_j<M:
                return go('top',next_j,0,4)
            elif where == 'top' and 0<=M-1-next_j<M:
                return go('buk',0,M-1-next_j,4)
            elif where == 'dong' and 0<=M-1-next_i<M and 0<=M-1:
                return go('top',M-1-next_i,M-1,4)
            elif where == 'buk' and 0<=M-1-next_j<M:
                return go('top',0,M-1-next_j,4)
            elif where == 'nam' and 0<=next_j<M and 0<=M-1:
                return go('top',M-1,next_j,4)
        elif next_i >= M:
            if where == 'seo' and 0<=s_p[0]+next_j<N and 0<=s_p[1]-1<N:
                return go('miji',s_p[0]+next_j,s_p[1]-1,4)
            elif where == 'top' and 0<=next_j<M:
                return go('nam',0,next_j,4)
            elif where == 'dong' and 0<=s_p[0]+M-1-next_j<N and 0<=s_p[1]+M<N:
                return go('miji',s_p[0]+M-1-next_j,s_p[1]+M,4)
            elif where == 'buk' and 0<=s_p[0]-1<N and 0<=s_p[1]+M-1-next_j<N:
                return go('miji',s_p[0]-1,s_p[1]+M-1-next_j,4)
            elif where == 'nam' and 0<=s_p[0]+M<N and 0<=s_p[1]+next_j<N:
                # print(where,next_i,next_j)
                # print(s_p[0],M)
                # print(s_p[0]+M,s_p[1]+next_j)
                return go('miji',s_p[0]+M,s_p[1]+next_j,4)

#----
        

#---계산시작

now = 0



while q:
    where, i, j, day = q.popleft()
    # print(where,i,j,day)
    # print(q)
    if now != day:
        now=day
        new_isang = []
        for r,c,d,v,where2 in isang:
            if (now+1) % v == 0:
                # print(miji_board)
                ret = go(where2,r,c,d,isang=True)
                if ret != False and ret != 9 and ret != None:
                    new_isang.append([ret[1],ret[2],d,v,ret[0]])
                # print("now")
                # print(isang)
                # print(miji_board)
            else:
                new_isang.append([r,c,d,v,where2])
        isang = new_isang
    for k in range(4):
        tmp = go(where,i,j,k)
        if tmp == 9:
            print(day+1)
            exit()
        if tmp:
            q.append([tmp[0],tmp[1],tmp[2],day+1])
print(-1)
# for i in range(len(miji_board)):
#     print(miji_board[i])


#-----