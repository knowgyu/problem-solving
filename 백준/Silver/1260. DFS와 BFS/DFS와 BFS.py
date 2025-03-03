from collections import defaultdict, deque
def dfs(graph, start, visited):
    visited[start] = True
    print(start, end=' ')
    for neighbor in sorted(graph[start]):
        if not visited[neighbor]:
            dfs(graph, neighbor, visited)


def bfs(graph, start):
    visited = [False] * (n + 1)
    queue = deque([start])
    visited[start] = True

    while queue:
        current = queue.popleft()
        print(current, end=' ')
        for neighbor in sorted(graph[current]):
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

n, m, v = map(int, input().split())
graph = defaultdict(set)

for _ in range(m):
    u, w = map(int, input().split())
    graph[u].add(w)
    graph[w].add(u)

visited = [False] * (n + 1)
dfs(graph, v, visited)
print()
bfs(graph, v)
