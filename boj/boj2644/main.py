import sys
from collections import deque

n = int(sys.stdin.readline())

f,s = map(int,sys.stdin.readline().split())

m = int(sys.stdin.readline())

graph = [[False]*(n+1) for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(m):
    a, b = map(int,sys.stdin.readline().split())
    graph[a][b] = True
    graph[b][a] = True

d = deque()

d.append((f,0))
visited[f] = True

while d:
    a, b = d.popleft()
    if a == s:
        print(b)
        exit()
    for i in range(1,n+1):
        if graph[a][i] == True and visited[i] == False:
            d.append((i,b+1))
            visited[i] = True

print(-1)
