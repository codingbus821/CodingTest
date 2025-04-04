import sys
from queue import PriorityQueue
import heapq

heap = []
name_to_val = {}
name=set()
val=set()

Q = int(sys.stdin.readline())

for _ in range(Q):
    s = sys.stdin.readline().strip().split()

    if s[0] == 'init':
        heap=[]
        name=set()
        val=set()
    elif s[0] == 'insert':
        n = s[1]
        v = int(s[2])
        
        if n not in name and v not in val:
            name.add(n)
            val.add(v)
            name_to_val[n] = v
            heapq.heappush(heap, (v,n))
            print(1)
        else:
            print(0)
        
    elif s[0] == 'delete':
        n = s[1]
        
        if n in name:
            print(name_to_val[n])
            name.remove(n)
            val.remove(name_to_val[n])
        else:
            print(0)
            
    elif s[0] == 'rank':
        k = int(s[1])
        if k > len(name):
            print("None")
            continue
        tmp = 0
        chk = False
        
        tmp_list = []
        
        while len(heap) != 0:
            v, n = heapq.heappop(heap)
            tmp_list.append((v,n))
            if n in name and name_to_val[n] == v:
                tmp += 1
            if k == tmp:
                print(n)
                chk = True
                break
        
        if chk == False:
            print("None")
        
        for v, n in tmp_list:
            heapq.heappush(heap, (v,n))
        
    else:
        k = int(s[1])
        su = 0
        for v in val:
            if v <= k:
                su += v
        print(su)