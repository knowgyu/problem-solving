def d(n):
    return n + sum(int(x) for x in str(n))

gn = set()
for i in range(1, 10001):
    dn = d(i)
    if dn <= 10000:
        gn.add(dn)

for i in range(1, 10001):
    if i not in gn:
        print(i)
