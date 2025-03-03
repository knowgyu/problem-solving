N=int(input())
cnt,i,digit=0,1,1
while i<=N:
    nxt=i*10-1
    if nxt>N: nxt=N
    cnt+=(nxt-i+1)*digit
    i*=10
    digit+=1
print(cnt)