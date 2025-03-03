N = int(input())
M = int(input())
b = set(input().split()) if M else set()

mn = abs(N - 100)
for ch in range(1000000):
    for c in str(ch):
        if c in b:
            break
    else:
        pr = len(str(ch)) + abs(N - ch)
        mn = min(mn, pr)

print(mn)
