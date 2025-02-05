from collections import deque

n, k = map(int, input().split())
coins = list(set(int(input()) for _ in range(n)))  # 중복 제거
coins.sort(reverse=True)  # 큰 동전부터 시도 (그리디 탐색 우선순위)

queue = deque([(0, 0, [])])  # (현재 금액, 동전 개수, 사용한 동전 리스트)
visited = set()  # 방문한 금액을 저장 (중복 방지)

while queue:
    current, count, used_coins = queue.popleft()

    if current == k:  # 목표 금액을 정확히 만들었다면
        print(f"사용한 동전: {used_coins}")
        print(count)
        exit()
    
    for coin in coins:
        new_value = current + coin
        if new_value <= k and new_value not in visited:
            visited.add(new_value)
            queue.append((new_value, count + 1, used_coins + [coin]))

print(-1)  # 만들 수 없는 경우
