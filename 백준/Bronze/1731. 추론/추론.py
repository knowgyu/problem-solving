import sys
input = sys.stdin.readline

N = int(input())
lst = [int(input()) for _ in range(N)]

if lst[2] - lst[1] == lst[1] - lst[0]:
    d = lst[1] - lst[0]
    print(lst[N-1] + d)
else:
    r = lst[1] / lst[0]
    print(int(lst[N-1] * r))