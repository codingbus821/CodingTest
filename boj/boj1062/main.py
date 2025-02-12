import itertools

N, K = map(int, input().split())

char_set = set()
ret = 0
word_list = []
for _ in range(N):
    s = input()
    word_mask = 0
    for c in s[4:-4]:
        if c not in "antic":
            word_mask |= (1 << (ord(c) - ord('a')))
            char_set.add(c)
    word_list.append(word_mask)

if len(char_set) <= K-5:
    print(N)
    exit()
            
if K < 5:
    print(0)
    exit()

combi = list(itertools.combinations(char_set, K-5))

for c in combi:
    tmp = 0
    selected_char = 0
    for i in c:
        selected_char |= (1<<ord(i)-ord('a'))
    for word in word_list:
        if word & selected_char == word:
            tmp += 1
    ret = max(tmp,ret)

print (ret)