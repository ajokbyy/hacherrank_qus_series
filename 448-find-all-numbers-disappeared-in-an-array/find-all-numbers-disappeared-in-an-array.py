class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)

        # Mark visited numbers
        for i in range(n):
            index = abs(nums[i]) - 1
            nums[index] = -abs(nums[index])

        # Collect missing numbers
        result = []
        for i in range(n):
            if nums[i] > 0:
                result.append(i + 1)

        return result

        