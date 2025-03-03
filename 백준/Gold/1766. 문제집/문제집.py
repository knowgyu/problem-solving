import sys
from collections import defaultdict, deque
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())

indegree = [0] * (N + 1)
graph = defaultdict(list)

for _ in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)
    indegree[B] += 1

heap = []
for i in range(1, N + 1):
    if indegree[i] == 0:
        heapq.heappush(heap, i)

result = []
while heap:
    c = heapq.heappop(heap)
    result.append(c)
    for n in graph[c]:
        indegree[n] -= 1
        if indegree[n] == 0:
            heapq.heappush(heap, n)

print(' '.join(map(str, result)))
