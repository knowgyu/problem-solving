import sys
input = sys.stdin.readline
#sys.stdin = open('input.txt', 'r')

N,M = map(int, input().split())
nohear = set()
nosee = set()
for _ in range(N):
    d = input().rstrip()
    nohear.add(d)
for _ in range(N):
    d = input().rstrip()
    nosee.add(d)

nn = sorted(nohear & nosee)
print(len(nn))
print(*nn,sep='\n')
