def calc(si,sj):
    wcnt = 0
    bcnt = 0

    for i in range(8):
        for j in range(8):
            if (i+j)%2==0 and arr[si+i][sj+j] == 'B':
                wcnt += 1
            elif (i+j)%2==1 and arr[si+i][sj+j] == 'W':
                wcnt += 1


    for i in range(8):
        for j in range(8):
            if (i+j)%2==0 and arr[si+i][sj+j] == 'W':
                bcnt += 1
            elif (i+j)%2==1 and arr[si+i][sj+j] == 'B':
                bcnt += 1

    return min(wcnt,bcnt)

N,M = map(int, input().split())
arr = [list(input()) for _ in range(N)]

ans = M*N
for i in range(N-8+1):
    for j in range(M-8+1):
        ans = min(ans,calc(i,j))
print(ans)