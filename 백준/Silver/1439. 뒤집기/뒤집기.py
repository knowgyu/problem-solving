s = input()

count0 = count1 = 0
current = s[0]

if current == '0':
    count0 += 1
else:
    count1 += 1

for char in s[1:]:
    if char != current:
        if char == '0':
            count0 += 1
        else:
            count1 += 1
        current = char

print(min(count0, count1))