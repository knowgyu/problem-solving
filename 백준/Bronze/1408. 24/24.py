ct = list(map(int, input().split(':')))
st = list(map(int, input().split(':')))

cts = 3600*ct[0] + 60*ct[1] + ct[2]
sts = 3600*st[0] + 60*st[1] + st[2]
one_day = 86400

# 시작 시간에서 24시간 후의 시간 계산
target_seconds = (sts + one_day) % one_day

# 남은 시간 계산
if cts > sts:
    remaining_seconds = target_seconds + one_day - cts
else:
    remaining_seconds = target_seconds - cts

h = remaining_seconds // 3600
m = (remaining_seconds % 3600) // 60
s = remaining_seconds % 60

print(f'{h:02}:{m:02}:{s:02}')
