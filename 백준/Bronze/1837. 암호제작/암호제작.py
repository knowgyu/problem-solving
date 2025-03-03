def solve(p, k):
    for i in range(2, k):
        if p % i == 0:
            return f"BAD {i}"

    return "GOOD"

p, k = map(int, input().split())
print(solve(p, k))