def solve(N):
    def is_prime(n):
        if n <= 1:
            return False
        if n <= 3:
            return True
        if n % 2 == 0 or n % 3 == 0:
            return False
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
        return True

    def is_palln(n):
        return str(n) == str(n)[::-1]

    i = N
    while True:
        if is_palln(i) and is_prime(i):
            return i
        i += 1

N = int(input().strip())
print(solve(N))
