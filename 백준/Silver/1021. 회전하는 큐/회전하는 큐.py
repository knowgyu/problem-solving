from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
positions = list(map(int, input().split()))

q = deque(range(1, N+1))
ans = 0

for position in positions:
    idx = q.index(position)
    if idx < len(q) - idx:
        q.rotate(-idx)
        ans += idx
    else:
        q.rotate(len(q) - idx)
        ans += len(q) - idx
    q.popleft()

print(ans)
