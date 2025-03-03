from math import floor
a,b,c=map(int,input().split())
if b==c: print(-1)
else:
    ans = floor(a/(c-b))+1
    if ans<=0: print(-1)
    else: print(ans)