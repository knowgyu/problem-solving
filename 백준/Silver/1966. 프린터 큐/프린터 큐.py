from collections import deque

import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    N,M = map(int, input().split())
    lst = list(map(int, input().split()))
    target = lst[M]
    tlst = deque(enumerate(lst))
    i = 0
    while True:
        current = tlst.popleft()
        if any(current[1] < other[1] for other in tlst):
            tlst.append(current)

        # 맞으면 idx 확인
        else:
            i += 1
            if current[0] == M:
                ans = i
                break
    print(ans)