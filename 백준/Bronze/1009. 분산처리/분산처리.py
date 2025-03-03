import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a,b = map(int, input().split())
    lst = []
    for i in range(1,11):
        n = (a**i) % 10
        if n in lst:
            break
        lst.append(n)

    ans = lst[(b-1) % len(lst)]
    print(ans if ans != 0 else 10)