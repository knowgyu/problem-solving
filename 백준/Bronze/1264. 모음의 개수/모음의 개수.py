from collections import defaultdict
import sys
input = sys.stdin.readline

while True:
    S = input().rstrip()
    if S=='#':
        break

    vowel = defaultdict(int)
    for c in S:
        vowel[c] += 1

    ans = vowel['a'] + vowel['e'] + vowel['i'] + vowel['o'] + vowel['u'] \
            + vowel['A'] + vowel['E'] + vowel['I'] + vowel['O'] + vowel['U']
    print(ans)