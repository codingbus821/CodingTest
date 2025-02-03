n, k = map(int, input().split())
ret = 0
n_list = []

for _ in range(n):
    n_list.append(int(input()))

def dfs(sum, ex):
    global k, ret, n_list
    if sum > k:
        return
    if sum == k:
        ret += 1
        return
    for i in n_list:
        if i >= ex:
            print(sum, i)
            dfs(sum+i, i)

for i in n_list:
    dfs(i, i)

print(ret)