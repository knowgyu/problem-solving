n=input()
tbl=[0]*26
for c in n:
    num = (ord(c.lower()) - 97)
    tbl[num] += 1

cnt = 0
mx = max(tbl)
for i in range(26):
    if tbl[i] == mx:
        cnt += 1

if cnt == 1:
    idx = tbl.index(mx)
    ans = chr(idx+97)
    print(ans.upper())
else:
    print('?')
