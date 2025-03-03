import sys
from collections import defaultdict
input = sys.stdin.readline

N=int(input())
nums = [int(input()) for _ in range(N)]

mean = round(sum(nums) / N)

nums.sort()
median = nums[N // 2]

freq = defaultdict(int)
for num in nums:
    freq[num] += 1
sorted_freq = sorted(freq.items(), key=lambda x: (-x[1], x[0]))
mode = sorted_freq[0][0]
if len(sorted_freq) > 1 and sorted_freq[0][1] == sorted_freq[1][1]:
    mode = sorted_freq[1][0]

range_val = nums[-1] - nums[0]

print(mean)
print(median)
print(mode)
print(range_val)
