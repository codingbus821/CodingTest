T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
dic = {'red' : 0, 'orange': 1, 'yellow': 2, 'green':3, 'blue':4, 'purple':5}
for test_case in range(1, T + 1):
    s = input().split()
    
    s0 = dic[s[0]]
    s1 = dic[s[1]]
    
    if s0 == s1:
        print('E')
    elif abs(s0-s1) == 1 or abs(s0-s1) == 5:
        print('A')
    elif abs(s0-s1) == 3:
        print('C')
    else:
        print('X')