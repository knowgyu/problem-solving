import sys
input = sys.stdin.readline


K,N=map(int, input().split())
klst = [int(input()) for _ in range(K)]

low, high = 1, max(klst)

while low <= high:
    mid = (low + high) // 2
    count = sum(l // mid for l in klst)

    if count >= N:
        low = mid + 1
    else:
        high = mid - 1

print(high)