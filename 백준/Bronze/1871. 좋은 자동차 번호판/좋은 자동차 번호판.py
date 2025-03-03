for _ in range(int(input())):
    L,D = input().split('-')
    L = L[::-1]
    l = 0
    d = int(D)
    for i in range(len(L)):
        l += (ord(L[i])-ord('A')) * 26**i
    print('nice') if abs(l-d) <= 100 else print('not nice')