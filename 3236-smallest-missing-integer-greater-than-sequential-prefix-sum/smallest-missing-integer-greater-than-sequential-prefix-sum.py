class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        total = nums[0]

        # Step 1: Sum consecutive prefix
        for i in range(1, len(nums)):
            if nums[i] == nums[i - 1] + 1:
                total += nums[i]
            else:
                break

        # Step 2: Use a set for fast lookup
        s = set(nums)

        # Step 3: Find smallest missing >= total
        while total in s:
            total += 1

        return total
        