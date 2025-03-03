import sys
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())
lst = []
for _ in range(N):
    M, V = map(int, input().split())
    lst.append((M, V))

bags = []
for _ in range(K):
    C = int(input().strip())
    bags.append(C)

lst.sort()
bags.sort()

mxheap = []
ans = 0
j = 0

for capa in bags:
    while j < N and lst[j][0] <= capa:
        heapq.heappush(mxheap, -lst[j][1])
        j += 1

    if mxheap:
        ans -= heapq.heappop(mxheap)

print(ans)