import sys
input = sys.stdin.readline

def bfs(s):
    q = []
    v = [0]*N

    q.append(s)
    v[s] = 1

    while q:
        c = q.pop(0)
        for n in graph[c]:
            if v[n] == 0:
                q.append(n)
                v[n] = v[c] + 1

    return sum(v)-5

N,M =map(int, input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a,b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

num = int(1E9)
for i in range(N):
    value = bfs(i)
    if value < num:
        num = value
        ans = i+1
print(ans)