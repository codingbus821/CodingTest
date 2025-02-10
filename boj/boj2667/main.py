N = int(input())

jido = [list(map(int, input())) for _ in range(N)]

danji_num = 0
house_num_list = []
house_num = 0

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

def dfs(i, j):
    global house_num
    house_num += 1
    jido[i][j] = 0
    
    for k in range(4):
        if i + dy[k] >= 0 and i + dy[k] < N and j + dx[k] >= 0 and j + dx[k] < N and jido[i + dy[k]][j + dx[k]] == 1:
            dfs(i+dy[k], j+dx[k])
    
    
for i in range(len(jido)):
    for j in range(len(jido[i])):
        if jido[i][j] == 1:
            danji_num += 1
            house_num = 0
            dfs(i, j)
            house_num_list.append(house_num)

house_num_list.sort()

print(danji_num)
for i in house_num_list:
    print(i)