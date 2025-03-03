N = int(input())

l = r = 1
sm = 0
ans = 0
while r <= N + 1:
    if sm < N:
        sm += r
        r += 1
    elif sm > N:
        sm -= l
        l += 1
    else:
        ans += 1
        sm += r
        r += 1
print(ans)
