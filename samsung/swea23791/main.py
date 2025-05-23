T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    
    n_list = [False] * (N+1)
    a_list = list(map(int,input().split()))
    b_list = list(map(int,input().split()))
    
    a_num = 0
    b_num = 0
    
    for i in range(N):
        
        for j in range(a_num, len(a_list)):
            if n_list[a_list[j]] == False:
                n_list[a_list[j]] = 'A'
                a_num = j + 1
                break
        for k in range(b_num, len(b_list)):
            if n_list[b_list[k]] == False:
                n_list[b_list[k]] = 'B'
                b_num = k + 1
                break
        
    
    print("".join(n_list[1:N+1]))