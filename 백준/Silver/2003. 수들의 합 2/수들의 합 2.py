N,M = map(int, input().split())
lst = list(map(int, input().split()))

l=r=0
sm = 0
ans = 0
while r<len(lst):
    sm += lst[r]
    r += 1

    while sm>M and l<r:
        sm -= lst[l]
        l += 1

    if sm == M:
        ans += 1
print(ans)