import sys
input = sys.stdin.readline

from heapq import heappop,heappush

h = []
N = int(input())
for _ in range(N):
    x=int(input())
    if len(h)==0 and x == 0:
        print(0)
    elif x==0:
        print(heappop(h))
    else:
        heappush(h,x)