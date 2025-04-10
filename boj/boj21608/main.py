import sys

N = int(sys.stdin.readline())
dic = {}

board = [[0] * N for _ in range(N)]

dy = [1,0,-1,0]
dx = [0,1,0,-1]

dic = {}

for _ in range(N*N):
    stu_num, f1,f2,f3,f4 = map(int,sys.stdin.readline().split())
    # print(stu_num,f1,f2,f3,f4)
    dic[stu_num] = [f1,f2,f3,f4]
    place = 0
    maxf = -1
    maxe = -1
    for i in range(N):
        for j in range(N):
            if board[i][j] == 0:
                f_num=0
                e_num=0
                for d in range(4):
                    ny, nx = i + dy[d], j + dx[d]
                    if 0<=ny<N and 0<=nx<N:
                        if board[ny][nx] == 0:
                            e_num += 1
                        if board[ny][nx] in (f1,f2,f3,f4):
                            f_num += 1
                if f_num > maxf:
                    place = (i,j)
                    maxf = f_num
                    maxe = e_num
                if f_num == maxf and maxe < e_num:
                    place = (i,j)
                    maxf = f_num
                    maxe = e_num
    board[place[0]][place[1]] = stu_num
    # print(board)

# print(dic)
ret = 0
for i in range(N):
    for j in range(N):
        stu=board[i][j]
        tmp = 0
        for d in range(4):
            ny, nx = i + dy[d], j + dx[d]
            if 0<=ny<N and 0<=nx<N:
                if board[ny][nx] in dic[stu]:
                    tmp += 1
        if tmp == 1:
            ret += 1
        elif tmp == 2:
            ret += 10
        elif tmp == 3:
            ret += 100
        elif tmp == 4:
            ret += 1000
print(ret)