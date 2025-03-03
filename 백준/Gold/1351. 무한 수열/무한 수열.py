from collections import defaultdict
N,P,Q=map(int, input().split())

dct = defaultdict(int)
dct[0] = 1

def solve(n):
    if n in dct:
        return dct[n]
    result = solve(n//P) + solve(n//Q)
    dct[n] = result
    return result

print(solve(N))