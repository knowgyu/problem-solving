def solve(n, r, c):
    order = 0
    size = 2 ** n

    while size > 1:
        size //= 2
        quad = (r // size) * 2 + (c // size)
        order += quad * (size ** 2)

        r %= size
        c %= size
    return order


n, r, c = map(int, input().split())
print(solve(n, r, c))
