n, k = map(int, input().split())

n_set = set()

ret = 111111

for _ in range(n):
    n_set.add(int(input()))

n_list = list(n_set)

n_list.sort(reverse=True)

for i in range(len(n_list)):
    tmp_sum = 0
    de = k
    if de == 0 or n_list[i] == 0:
        break
    if de / n_list[i] > 0:
        tmp_sum += de // n_list[i]
        de = de % n_list[i]
        for j in range(i+1, len(n_list)):
            if de == 0 or n_list[j] == 0:
                break
            if de / n_list[j] > 0:
                tmp_sum += de // n_list[j]
                de = de % n_list[j]
    if de == 0 and tmp_sum < ret:
        ret = tmp_sum
if ret == 111111:
    print(-1)
else: 
    print(ret)