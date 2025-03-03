N = input()
lst = [0]*10

for c in N:
    lst[int(c)] += 1

if lst[6]!=lst[9]:
    if (lst[6]+lst[9]) % 2 == 0:
        sm = lst[6]+lst[9]
        lst[6] = lst[9] = sm//2
    else:
        sm = lst[6]+lst[9]
        lst[6] = sm//2 + 1
        lst[9] = sm//2

print(max(lst))