from collections import deque

dy = [0,1,0,-1]
dx = [1,0,-1,0]

N, M = map(int, input().split())

m = [[0] * (N) for _ in range(M)]
visited = [[False] * (N) for _ in range(M)]

ans0 = 0
ans1 = 0

for i in range(M):
    s = input()
    for j in range(len(s)):
        if s[j] == 'W':
            m[i][j] = 0
        else:
            m[i][j] = 1

for i in range(M):
    for j in range(N):
        if visited[i][j] == False and m[i][j] == 0:
            visited[i][j] = True
            d = deque()
            d.append([i,j])
            tmp = 1
            while d:
                f, s = d.popleft()
                for ii in range(4):
                    if 0 <= f+dy[ii] < M and 0 <= s+dx[ii] < N and visited[f+dy[ii]][s+dx[ii]] == False and m[f+dy[ii]][s+dx[ii]] == 0:
                        d.append([f+dy[ii], s+dx[ii]])
                        visited[f+dy[ii]][s+dx[ii]] = True
                        tmp += 1
            ans0 += tmp*tmp
                
        if visited[i][j] == False and m[i][j] == 1:
            visited[i][j] = True
            d = deque()
            d.append([i,j])
            tmp = 1
            while d:
                f, s = d.popleft()
                for ii in range(4):
                    if 0 <= f+dy[ii] < M and 0 <= s+dx[ii] < N and visited[f+dy[ii]][s+dx[ii]] == False and m[f+dy[ii]][s+dx[ii]] == 1:
                        d.append([f+dy[ii], s+dx[ii]])
                        visited[f+dy[ii]][s+dx[ii]] = True
                        tmp += 1
            ans1 += tmp*tmp

print(ans0, ans1)