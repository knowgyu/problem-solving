import sys
input = sys.stdin.readline

def find(parent, i):
    if parent[i] != i:
        parent[i] = find(parent, parent[i])
    return parent[i]

def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)
    if rootX != rootY:
        if rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        elif rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        else:
            parent[rootY] = rootX
            rank[rootX] += 1

def kruskal(n, edges):
    parent = list(range(n + 1))
    rank = [0] * (n + 1)
    mst_cost = 0
    edge_count = 0

    edges.sort()  # 가중치에 따라 간선을 정렬

    for weight, u, v in edges:
        if find(parent, u) != find(parent, v):
            union(parent, rank, u, v)
            mst_cost += weight
            edge_count += 1
            if edge_count == n - 1:
                break

    return mst_cost

n,m = map(int, input().split())
edges = []

for _ in range(m):
    u,v,w = map(int, input().split())
    edges.append((w, u, v))

print(kruskal(n, edges))
