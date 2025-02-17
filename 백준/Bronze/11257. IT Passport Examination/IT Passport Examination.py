import sys, math
input = sys.stdin.readline
n = int(input())
for _ in range(n):
    a = input().split()
    num = a[0]
    s = list(map(int, a[1:]))
    t = sum(s)
    if t >= 55 and s[0] >= math.ceil(35 * 0.3) and s[1] >= math.ceil(25 * 0.3) and s[2] >= math.ceil(40 * 0.3):
        r = "PASS"
    else:
        r = "FAIL"
    print(num, t, r)
