def solve(N, F):
    n = N[:-2]
    for i in range(100):
        tar = n + f'{i:02d}'
        N = int(tar)

        if N%F == 0:
            return f'{i:02d}'
    return -1
N = input()
F=int(input())
print(solve(N,F))