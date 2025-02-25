from collections import deque
import sys

S = int(sys.stdin.readline())
visited = [[False] * 1001 for _ in range(1001)]

d = deque()
d.append([1, 0, 0])
visited[1][0] = True

while d:
    now, clip, T = d.popleft()
    if now == S:
        print(T)
        break
    for i in range(3):
        if i == 0:
            new_now, new_clip = now, now
        elif i == 1:
            new_now, new_clip = now+clip, clip
        else:
            new_now, new_clip = now-1, clip
        if 0<new_now<=1000 and 0<new_clip<=1000 and visited[new_now][new_clip] == False:
            d.append([new_now, new_clip, T+1])
            visited[new_now][new_clip] = True