import sys


def kadanes(nums: list[int]) -> int:
    maxI = -sys.maxsize - 1
    sum = 0

    for i in nums:
        sum += nums[i]
        if sum > maxI:
            maxI = sum

        if sum < 0:
            sum = 0

        return maxI


result = kadanes([2, 3, 4, 5, -5, 7, -5])
print(result)
