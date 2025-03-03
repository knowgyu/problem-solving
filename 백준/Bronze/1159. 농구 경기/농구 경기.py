import sys
input = sys.stdin.readline

lst = [0]*26
N = int(input())
for _ in range(N):
    t = input().rstrip()[0]
    lst[ord(t)-ord('a')]+=1

if (max(lst) <5): print("PREDAJA")
else:
    for i in range(26):
        if lst[i] >= 5:
            print(chr(i+ord('a')),end="")