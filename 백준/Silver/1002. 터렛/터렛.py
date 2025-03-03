T = int(input())
for _ in range(T):
    x1,y1,r1,x2,y2,r2 = map(int, input().split())

    dist = (x1-x2)**2 + (y1-y2) **2
    if dist == 0 and r1==r2:
        print(-1)
    elif dist == (r1+r2)**2 or dist==(r1-r2)**2:
        print(1)
    elif (r1-r2)**2 < dist < (r1+r2)**2:
        print(2)
    else:
        print(0)
