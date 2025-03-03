import heapq
import sys
input = sys.stdin.readline
INF = int(1E9)

def dijkstra(s, g, n):
    d = [INF] * (n + 1)
    d[s] = 0
    q = [(0, s)]

    while q:
        cd, cn = heapq.heappop(q)
        if d[cn] < cd:
            continue
        for v, w in g[cn]:
            nd = cd + w
            if nd < d[v]:
                d[v] = nd
                heapq.heappush(q, (nd, v))
    return d

n, e = map(int, input().split())
s = int(input())

g = [[] for _ in range(n + 1)]
for _ in range(e):
    u, v, w = map(int, input().split())
    g[u].append((v, w))

d = dijkstra(s, g, n)

for i in range(1, n + 1):
    print("INF" if d[i] == INF else d[i])
