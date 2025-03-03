lst = [0]*26
while True:
    try:
        S = input().rstrip()
    except:
        break


    for c in S:
        if c ==' ': continue
        idx = ord(c) - ord('a')
        lst[idx] += 1

for idx in range(len(lst)):
    if lst[idx] == max(lst):
        print(chr(idx+ord('a')),end='')