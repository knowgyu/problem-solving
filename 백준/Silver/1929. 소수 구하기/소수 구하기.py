M, N = map(int, input().split())

is_prime = [True] * (N + 1)
is_prime[0], is_prime[1] = False, False

for start in range(2, int(N**0.5) + 1):
    if is_prime[start]:
        is_prime[start*start:N + 1:start] = [False] * ((N - start*start) // start + 1)

for num in range(M, N + 1):
    if is_prime[num]:
        print(num)
