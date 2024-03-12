def kadanes(nums: list[int]) -> int:
    max_i = float("-inf")
    sum = 0

    for i in range(len(nums)):
        sum += nums[i]

        if sum > max_i:
            max_i = sum

        if sum < 0:
            sum = 0

    return max_i

result = kadanes([2, -5, 4, 5, -5, 2, -5])
print(result)
