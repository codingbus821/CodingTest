import sys

N = int(sys.stdin.readline())

def bi(num, max):
    ans = ""
    while (num // 2) != 0:
        ans = str(num % 2) + ans
        num=num // 2
    
    ans = str(num % 2) + ans

    while len(ans) < max:
        ans = "0" + ans
    
    return ans    
    
for _ in range(N):
    s = sys.stdin.readline().split()
    ans = ""
    if "ADD" in s[0]:
        ans += "0000"
    elif "SUB" in s[0]:
        ans += "0001"
    elif "MOV" in s[0]:
        ans += "0010"
    elif "AND" in s[0]:
        ans += "0011"
    elif "OR" in s[0]:
        ans += "0100"
    elif "NOT" in s[0]:
        ans += "0101"
    elif "MULT" in s[0]:
        ans += "0110"
    elif "LSFTL" in s[0]:
        ans += "0111"
    elif "LSFTR" in s[0]:
        ans += "1000"
    elif "ASFTR" in s[0]:
        ans += "1001"
    elif "RL" in s[0]:
        ans += "1010"
    elif "RR" in s[0]:
        ans += "1011"
        
    if s[0][-1] == "C":
        ans += "10"
    else:
        ans += "00"
    
    ans += bi(int(s[1]), 3)

    ans += bi(int(s[2]), 3)

    if s[0][-1] == "C":
        ans += bi(int(s[3]), 4)
    else:
        ans += bi(int(s[3]), 3) + "0"
    
    print(ans)