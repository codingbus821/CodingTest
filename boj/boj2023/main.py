import sys
sys.setrecursionlimit(10000)

N = int(sys.stdin.readline())

def sosoo(num):
    for i in range(2, int(num/2)+1):
        if num % i == 0:
            return False
    return True

def dfs(now):
    global N
    
    if now / 10 ** (N-1) > 1:
        print(now)
        return
    
    for i in (1,3,5,7,9):
        if sosoo(now*10+i):
            dfs(now*10+i)
    

for i in (2,3,5,7):
    dfs(i)