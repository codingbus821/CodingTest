dy = [0,1,0,-1]
dx = [1,0,-1,0]
def dfs(i, j, chk):
    global m, visited, length_list, M, N
    visited[i][j] = True
    ret = 0
    for ii in range(4):
        if 0 <= i+dy[ii] < M and 0 <= j+dx[ii] < N and visited[i+dy[ii]][j+dx[ii]] == False and m[i+dy[ii]][j+dx[ii]] == chk:
            ret += dfs(i+dy[ii], j+dx[ii], chk)
        
    return ret + 1

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
            num=dfs(i, j, 0)
            ans0 += num*num
        if visited[i][j] == False and m[i][j] == 1:
            num=dfs(i, j, 1)
            ans1 += num*num

print(ans0, ans1)