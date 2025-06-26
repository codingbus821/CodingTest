N = int(input())

def star(n):
    if n == 3:
        return ['  *  ', ' * * ', '*****']
    else:
        l = star(n//2)
        tmp = ' ' * (n//2)
        for i in range(len(l)):
            l[i] = tmp + l[i] + tmp
        ll = star(n//2)
        for i in range(len(ll)):
            ll[i] =  ll[i] + " " + ll[i]
        return l + ll
        
s = star(N)

for i in s:
    print(i)