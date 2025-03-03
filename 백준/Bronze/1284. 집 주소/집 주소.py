while True:
    n = input()
    if n == "0":
        break
    w = 2
    for digit in n:
        if digit == '1':
            w += 2
        elif digit == '0':
            w += 4
        else:
            w += 3
    w += len(n) - 1
    print(w)