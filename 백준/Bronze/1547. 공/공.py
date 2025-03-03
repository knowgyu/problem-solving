import sys
input = sys.stdin.readline

M = int(input())
lst = [1,2,3]
for _ in range(M):
    x,y=map(int, input().split())
    xi = lst.index(x)
    yi = lst.index(y)
    lst[xi],lst[yi] = lst[yi],lst[xi]

print(lst[0])