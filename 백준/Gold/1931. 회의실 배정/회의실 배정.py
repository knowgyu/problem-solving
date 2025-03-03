import sys
input = sys.stdin.readline

N = int(input())
lst = []

index = 1
for _ in range(N):
    s,e = map(int, input().split())
    lst.append((s,e))

lst.sort(key=lambda x: (x[1], x[0]))

max_count = 0
last_end = 0
for start, end in lst:
    if start >= last_end:
        max_count += 1
        last_end = end

print(max_count)