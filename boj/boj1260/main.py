from collections import deque

def dfs(V):
    global m, visited, dfs_list
    dfs_list.append(V)
    visited[V] = True

    for i in range(1, N+1):
        if m[V][i] == 1 and visited[i] == False:
            dfs(i)
    
N, M, V = map(int, input().split())

m = [[0] * (N+1) for _ in range(N+1)]

for _ in range(M):
    s, e = map(int, input().split())
    m[s][e] = 1
    m[e][s] = 1

visited = [False] * (N+1)
dfs_list = []
dfs(V)

visited = [False] * (N+1)
bfs_list = []
d=deque()
d.append(V)
visited[V] = True
while d:
    v = d.popleft()
    bfs_list.append(v)
    for i in range(1, N+1):
        if m[v][i] == 1 and visited[i] == False:
            d.append(i)
            visited[i] = True

print(str([i for i in dfs_list]).replace('[','').replace(']','').replace(',',''))
print(str([i for i in bfs_list]).replace('[','').replace(']','').replace(',',''))