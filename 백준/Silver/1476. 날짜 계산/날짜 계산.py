e,s,m=map(int,input().split())
ans=1
i,j,k=1,1,1
while True:
    if (i,j,k) == (e,s,m):
        print(ans)
        break
    ans += 1
    i+=1
    j+=1
    k+=1
    if i>15:
        i=1
    if j>28:
        j=1
    if k>19:
        k=1
