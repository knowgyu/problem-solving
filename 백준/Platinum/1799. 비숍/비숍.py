N = int(input())
arr = [list(map(int, input().split())) for _ in range(N)]

lst = [[] for _ in range(2*N)]
for i in range(N):
    for j in range(N):
        if arr[i][j]==1:
            lst[i+j].append((i,j))
L = 2*N-1
v = [0]*(2*N)

def dfs(n, cnt):
    global ans
    if ans >= (cnt+(L+1-n)//2):
        return

    if n>=L:
        ans = max(ans, cnt)
        return

    for ci,cj in lst[n]:
        if v[ci-cj]==0:
            v[ci-cj]=1
            dfs(n+2, cnt+1)
            v[ci-cj]=0
    dfs(n+2, cnt)



ans = 0
dfs(0, 0)  
t = ans
ans = 0
dfs(1, 0)  
print(ans+t)