class Solution:
    def twoSum(self, nums, target):
        seen = {}   # stores number : index

        for i in range(len(nums)):
            current = nums[i]
            needed = target - current

            if needed in seen:
                return [seen[needed], i]

            seen[current] = i
