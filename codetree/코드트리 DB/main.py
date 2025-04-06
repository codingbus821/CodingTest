import sys

entry_count = 0
name_to_index = {}
used_values = set()
names = ["" for _ in range(100005)]
values = [0 for _ in range(100005)]

class SegmentTreeNode:
    def __init__(self):
        self.left=0
        self.right=0
        self.index = 0
        self.count = 0
        self.sum = 0

segment_tree=[]

def update(node_id, left, right, position, index, count, sum):
    if right < position or position < left:
        return
    
    if left == right:
        segment_tree[node_id].index = index
        segment_tree[node_id].count = count
        segment_tree[node_id].sum = sum
        return
    
    mid = (left + right) // 2

    if position <= mid:
        if not segment_tree[node_id].left:
            segment_tree[node_id].left = len(segment_tree)
            segment_tree.append(SegmentTreeNode())
        update(segment_tree[node_id].left, left, mid,position,index,count,sum)
    else:
        if not segment_tree[node_id].right:
            segment_tree[node_id].right = len(segment_tree)
            segment_tree.append(SegmentTreeNode())
        update(segment_tree[node_id].right, mid+1, right,position,index,count,sum)

    left_node = segment_tree[node_id].left
    right_node = segment_tree[node_id].right
    segment_tree[node_id].count = segment_tree[left_node].count+ segment_tree[right_node].count
    segment_tree[node_id].sum = segment_tree[left_node].sum + segment_tree[right_node].sum

def query_rank(node_id,left,right,rank):
    if left == right:
        return segment_tree[node_id].index
    mid = (left+right) // 2
    left_node = segment_tree[node_id].left
    if left_node:
        if segment_tree[left_node].count >= rank:
            return query_rank(left_node,left,mid,rank)
        return query_rank(segment_tree[node_id].right,mid+1,right,rank- segment_tree[left_node].count)
    return query_rank(segment_tree[node_id].right,mid+1,right,rank)

def query_sum(node_id,left,right,query_left,query_right):
    if query_right < left or right < query_left:
        return 0
    if query_left <= left and right<=query_right:
        return segment_tree[node_id].sum
    
    mid = (left+right) // 2
    
    result = 0

    if segment_tree[node_id].left:
        result += query_sum(segment_tree[node_id].left,left,mid,query_left,query_right)
    if segment_tree[node_id].right:
        result += query_sum(segment_tree[node_id].right, mid+1,right,query_left,query_right)
    return result

def handle_init():
    global entry_count
    segment_tree.clear()
    segment_tree.append(SegmentTreeNode())
    segment_tree.append(SegmentTreeNode())

    entry_count = 0
    name_to_index.clear()
    used_values.clear()

def handle_insert(name, value):
    global entry_count

    if name in name_to_index or value in used_values:
        print("0")
        return
    
    entry_count += 1
    name_to_index[name]= entry_count
    names[entry_count] = name
    used_values.add(value)
    values[entry_count] = value

    update(1,1,int(1e9),value,entry_count,1,value)
    print("1")

def handle_delete(name):
    if name not in name_to_index:
        print("0")
        return
    
    index = name_to_index[name]
    del name_to_index[name]
    used_values.remove(values[index])

    update(1,1,int(1e9),values[index],index,0,0)
    print(values[index])

def handel_rank(k):
    if segment_tree[1].count < k:
        print("None")
        return
    
    index = query_rank(1,1,int(1e9),k)
    print(names[index])

def handel_sum(k):
    sum_value = query_sum(1,1,int(1e9),1,k)
    print(sum_value)


Q = int(sys.stdin.readline())

for _ in range(Q):
    s = sys.stdin.readline().strip().split()

    if s[0] == 'init':
        handle_init()
    elif s[0] == 'insert':
        n = s[1]
        v = int(s[2])
        handle_insert(n,v)
    elif s[0] == 'delete':
        n = s[1]
        handle_delete(n)
    elif s[0] == 'rank':
        k = int(s[1])
        handel_rank(k)
    else:
        k = int(s[1])
        handel_sum(k)