for _ in range(int(input())):
    N = int(input())
    lst = list(map(float, input().split()))

    if N == 1:
        print("NO")
        continue

    lst.sort()
    sm = 0.0
    mx = 0.0
    ans = False

    for length in lst:
        mx = max(mx, length)
        sm += length
        if sm - mx >= mx:
            ans = True
            break

    if ans:
        print("YES")
    else:
        print("NO")