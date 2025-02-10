import sys

N = int(sys.stdin.readline())

all_list = []

def dfs(l):
    global all_list
    for i in range(1, l[-1]+1):
        l.append(l[-1] - i)
        s = ''.join(map(str,l))
        all_list.append(int(s))
        dfs(l)
        l.pop()

for i in range(10):
    all_list.append(i)
    dfs([i])

all_list.sort()

if N >= len(all_list):
    print(-1)
else:
    print(all_list[N])