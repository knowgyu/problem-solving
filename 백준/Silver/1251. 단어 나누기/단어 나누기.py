s = input()
ln = len(s)

alst = []
for i in range(ln-1):
    for j in range(i+1,ln):
        a = s[:i]
        b = s[i:j]
        c = s[j:]
        if(len(a) == 0 or len(b) == 0 or len(c) == 0):
            continue

        a = a[::-1]
        b = b[::-1]
        c = c[::-1]
        ans = a+b+c
        alst.append(ans)

alst.sort()
print(alst[0])