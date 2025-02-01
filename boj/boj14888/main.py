mi = 1111111111
ma = -1111111111

def next_num(loc, a, b, c, d, now):
    global mi, ma
    if loc == N:
        if now < mi:
            mi = now
        if now > ma:
            ma = now
        return

    if a>=1:
        next_num(loc+1, a-1, b, c, d, now + nums[loc])
    if b>=1:
        next_num(loc+1, a, b-1, c, d, now - nums[loc])
    if c>=1:
        next_num(loc+1, a, b, c-1, d, now * nums[loc])
    if d>=1:
        next_num(loc+1, a, b, c, d-1, int(now / nums[loc]))

N = int(input())

nums = list(map(int, input().split()))
op = list(map(int, input().split()))

next_num(1, op[0], op[1], op[2], op[3], nums[0])

    
print(ma)
print(mi)