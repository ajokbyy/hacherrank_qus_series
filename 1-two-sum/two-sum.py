class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}  # value : index # this is just a disnary
        for i, num in enumerate(nums):
            # enumerate() is a Python built-in function that gives you:
            # i → index (0, 1, 2, 3…), num → value from the list
            complement = target - num
            if complement in hashmap:
                return [hashmap[complement], i]
            hashmap[num] = i  

            