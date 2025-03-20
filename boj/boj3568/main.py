import sys

s = sys.stdin.readline().split()

for i in range(len(s) - 1):
    now_s = s[i+1]
    now_s = now_s[:-1]
    chk = False
    for j in range(len(now_s)):
        if not now_s[j].isalpha():
            
            new_s = now_s[j:]
            new_s = new_s[::-1]
            
            new_s = list(new_s)

            for k in range(len(new_s)):
                if new_s[k] == ']':
                    new_s[k] = '['
                elif new_s[k] == '[':
                    new_s[k] = ']'
            
            new_s = "".join(new_s)      
            s[i+1] = new_s+ " " +now_s[0:j]
            chk = True
            break
    if chk == False:
        s[i+1] = " " + now_s

for i in range(len(s) -1):
    print(s[0]+s[i+1]+";")