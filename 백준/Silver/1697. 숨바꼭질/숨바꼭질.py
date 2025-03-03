from collections import deque

N,K=map(int, input().split())

def bfs(s,e):
    q = deque()
    v=[0]*(100001)

    q.append(s)
    v[s] = 1

    while q:
        c = q.popleft()
        if c==e:
            return v[c]-1

        for d in (1,-1,c):
            n = c+d

            if 0<=n<=100000 and v[n]==0:
                q.append(n)
                v[n]=v[c]+1


print(bfs(N,K))