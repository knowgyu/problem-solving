from collections import deque

def solve(s):
    uniq = set(s)

    uniq_count = {} # {'A':2} {'B':2}처럼 되어있음
    cnt = 0

    odd_char = None
    for c in uniq:
        uniq_count[c] =s.count(c)
        if uniq_count[c] % 2 == 1:
            odd_char = c
            cnt += 1
            if cnt>=2:
                return "I'm Sorry Hansoo"

    else:
        uniq_count = dict(sorted(uniq_count.items(), reverse=True))

    if odd_char:    # 홀수개수인 애가 있으면 걔가 무조건 가운데로
        ans = deque()
        ans.append(f"{odd_char}")
        for char, num in uniq_count.items():
            for _ in range(num // 2):  # 2면 1번만 실행
                ans.appendleft(char)
                ans.append(char)

    else:           # 홀수개수 없으면 그냥 하면 됨.
        ans = deque()

        for char, num in uniq_count.items():
            for _ in range(num//2): # 2면 1번만 실행
                ans.appendleft(char)
                ans.append(char)


    anstr = ""
    while ans:
        c = ans.popleft()
        anstr+=c
    return anstr



s=input()
print(solve(s))

