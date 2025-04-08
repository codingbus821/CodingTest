import sys

N,M = map(int,sys.stdin.readline().split())

board = []
visited = [[False] * M for _ in range(N)]
dy = [-1,0,1,0]
dx = [0,1,0,-1]

ry, rx, rd = map(int,sys.stdin.readline().split())

for _ in range(N):
    board.append(list(map(int,sys.stdin.readline().split())))

ret = 0

while True:
    if visited[ry][rx] == False:
        visited[ry][rx] = True
        ret += 1
    # for i in range(len(visited)):
    #     print(visited[i])
    # print(rd)
    # print()
    for i in range(4):
        nry, nrx = ry+dy[i],rx+dx[i]
        if 0<=nry<N and 0<=nrx<M and board[nry][nrx] == 0 and visited[nry][nrx] == False:
            # print(rd)
            rd = (rd - 1)%4
            # print(rd)
            if board[ry+dy[rd]][rx+dx[rd]] == 0 and visited[ry+dy[rd]][rx+dx[rd]] == False:
                ry, rx = ry+dy[rd], rx+dx[rd]
            break
    else:
        if board[ry-dy[rd]][rx-dx[rd]] == 0:
            ry, rx = ry-dy[rd], rx-dx[rd]
        else:
            break
# print(visited)

print(ret)