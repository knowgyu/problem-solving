import sys
input = sys.stdin.readline
N=int(input())
lst = set()
for _ in range(N):
    wd = input().rstrip()
    lst.add(wd)
lst = sorted(lst, key=lambda x:(len(x), x))
print(*lst,sep='\n')