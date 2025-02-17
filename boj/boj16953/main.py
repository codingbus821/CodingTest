from collections import deque

A, B = map(int, input().split())

d = deque()

d.append([A, 1])

while d:
    f, s = d.popleft()
    if f == B:
        print(s)
        exit()
    if f*2 <= B:
        d.append([f*2, s+1])
    if f*10 + 1 <= B:
        d.append([f*10 + 1, s+1])

print(-1)