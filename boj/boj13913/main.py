from collections import deque

N, K = map(int, input().split())

d = deque()
visited = [-1] * 111111

d.append(N)

while d:
    f = d.popleft()
    if f == K:
        break
    for next in (f+1, f-1, f*2):
        if 0 <= next <= 100000 and visited[next] == -1:
            d.append(next)
            visited[next] = f

ans = [K]

if visited[K] == -1:
    print(0)
    print(K)
else:
    parent = visited[K]

    while parent != N:
        ans.append(parent)
        parent = visited[parent]

    ans.append(N)
    print(len(ans)-1)
    ans.reverse()
    print(*ans)