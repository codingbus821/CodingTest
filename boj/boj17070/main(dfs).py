N = int(input())

m = []
ans = 0

def dfs(sr, sc, er, ec):
    global m, ans
    
    if er == N-1 and ec == N-1:
        ans += 1
        return

    if sr == er:
        if ec+1 < N and m[er][ec+1] == 0:
            dfs(sr, sc+1, er, ec+1)
        if ec+1 < N and er+1 < N and m[er][ec+1] == 0 and m[er+1][ec+1] == 0 and m[er+1][ec] == 0:
            dfs(sr, sc+1, er+1, ec+1)
    
    elif sc == ec:
        if er+1 < N and m[er+1][ec] == 0:
            dfs(sr+1, sc, er+1, ec)
        if ec+1 < N and er+1 < N and m[er][ec+1] == 0 and m[er+1][ec+1] == 0 and m[er+1][ec] == 0:
            dfs(sr+1, sc, er+1, ec+1)

    else:
        if ec+1 < N and m[er][ec+1] == 0:
            dfs(sr+1, sc+1, er, ec+1)
        if er+1 < N and m[er+1][ec] == 0:
            dfs(sr+1, sc+1, er+1, ec)
        if ec+1 < N and er+1 < N and m[er][ec+1] == 0 and m[er+1][ec+1] == 0 and m[er+1][ec] == 0:
            dfs(sr+1, sc+1, er+1, ec+1)

for _ in range(N):
    m.append(list(map(int, input().split())))

if m[N-1][N-1] == 1:
    print(0)
    exit()

dfs(0,0,0,1)

print(ans)