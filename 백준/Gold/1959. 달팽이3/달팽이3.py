def snail_pattern(m, n):
    if m > n:
        # If the height is greater than the width
        turns = 2 * (n - 1) + 1
    else:
        # If the width is greater than or equal to the height
        turns = 2 * (m - 1)
    
    print(turns)
    
    if m == n:
        if m % 2 == 1:
            print((m - 1) // 2 + 1, (m - 1) // 2 + 1)
        else:
            print(m // 2 + 1, m // 2)
    else:
        if n > m:
            if m % 2 == 0:
                print(m // 2 + 1, m // 2)
            else:
                print(m // 2 + 1, m // 2 + 1 + (n - m))
        else:
            if n % 2 == 0:
                print(n // 2 + 1, n // 2)
            else:
                print(n // 2 + 1 + (m - n), n // 2 + 1)

m, n = map(int, input().split())
snail_pattern(m, n)