from itertools import permutations

def solve(N, M):
    for perm in permutations(range(1, N + 1)):
        current = list(perm)
        for i in range(1, N):
            current = [current[j] + current[j + 1] for j in range(N - i)]
        if current[0] == M:
            return perm

    return None

N, M = map(int, input().split())
result = solve(N, M)
if result:
    print(*result)
