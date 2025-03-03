while True:
    d = list(map(int, input().split()))
    if d[0] == 0:
        break
    a = d[0]
    f = d[1:]

    l = 1
    for i in range(a):
        s = f[2 * i]
        c = f[2 * i + 1]
        l = l * s - c
    print(l)