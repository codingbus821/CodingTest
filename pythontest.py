N = int(input())

arr = []

def check():
    for i in range(1, len(arr)//2+1):
        if arr[len(arr)-i:] == arr[len(arr)-2*i:len(arr)-i]:
            return 0
    return 1
def dfs(num):

    if len(arr) == N:
        print(''.join(map(str, arr)))
        exit(0)

    arr.append(num)
    if check():
        dfs(1)
        dfs(2)
        dfs(3)
    else:
        arr.pop()


dfs(1)