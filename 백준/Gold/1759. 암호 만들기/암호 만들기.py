from itertools import combinations

L, C = map(int, input().split())
lst = sorted(input().split())
vo = [x for x in lst if x in ('a', 'e', 'i', 'o', 'u')]

for pw in combinations(lst, L):
    vo_cnt, co_cnt = 0, 0
    for c in pw:
        if c in vo:
            vo_cnt += 1
        else:
            co_cnt += 1
    if vo_cnt < 1 or co_cnt < 2:
        continue
    else:
        print(*pw,sep='')
