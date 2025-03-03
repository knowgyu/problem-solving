import sys

input = sys.stdin.readline

n, l, d = map(int, input().split())
total = n * l + (n - 1) * 5
song = [False] * total

for i in range(0, total, l + 5):
    song[i:i+l] = [True] * l

for i in range(0, total, d):
    if not song[i]:
        print(i)
        break
else:
    print(i + d)