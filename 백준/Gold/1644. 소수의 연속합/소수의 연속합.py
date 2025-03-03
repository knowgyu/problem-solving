import sys
input = sys.stdin.readline

def sieve(n):
    is_prime = [True] * (n + 1)
    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for i in range(p*p, n+1, p):
                is_prime[i] = False
    return [p for p in range(2, n + 1) if is_prime[p]]

def count_prime_sums(n, primes):
    count, start, current_sum = 0, 0, 0
    for end in range(len(primes)):
        current_sum += primes[end]
        while current_sum > n and start <= end:
            current_sum -= primes[start]
            start += 1
        if current_sum == n:
            count += 1
    return count

N = int(input())
primes = sieve(N)
print(count_prime_sums(N, primes))
