import sys
from collections import deque, defaultdict

T = int(sys.stdin.readline())
    

for _ in range(T):
    K, M, P = map(int, sys.stdin.readline().split())
    
    indegree = [[0,0,0] for _ in range(M+1)]
    
    ndict = defaultdict(list)
    
    for _ in range(P):
        s, e = map(int, sys.stdin.readline().split())
        ndict[s].append(e)
        indegree[e][0] += 1
    
    d = deque()
    for i in range(1, M+1):
        if indegree[i][0] == 0:
            d.append(i)
            indegree[i][1] = 1

    while d:
        x = d.popleft()
        for i in ndict[x]:
            indegree[i][0] -= 1
            if indegree[i][1] < indegree[x][1]:
                indegree[i][1] = indegree[x][1]
                indegree[i][2] = 1
            elif indegree[i][1] == indegree[x][1]:
                indegree[i][2] += 1
            if indegree[i][0] == 0:
                if indegree[i][2] > 1:
                    indegree[i][1] += 1
                d.append(i)
    print(K, indegree[M][1])