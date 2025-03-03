import sys
input = sys.stdin.readline

from collections import deque

N,M=map(int, input().split())
arr = [list(map(int,input().split())) for _ in range(N)]
v=[[0]*M for _ in range(N)]

def bfs(si,sj):
    q=deque()
    q.append((si, sj))

    v[si][sj] = 1

    tlst = [(si,sj)]
    while q:
        ci,cj = q.popleft()

        for di,dj in ((-1,0),(1,0),(0,-1),(0,1)):
            ni,nj = ci+di,cj+dj
            if 0<=ni<N and 0<=nj<M and v[ni][nj] == 0 and arr[ni][nj] == 1:
                q.append((ni,nj))
                v[ni][nj] = 1
                tlst.append((ni, nj))



    return len(tlst)

mx,cnt = 0,0
for i in range(N):
    for j in range(M):
        if arr[i][j] == 1 and v[i][j]==0:
            area = bfs(i,j)
            cnt += 1
            if area > mx:
                mx = area

print(cnt)
print(mx)
