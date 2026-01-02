class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        rep = {}
        for i in nums:
            if i in rep:
                return i
            rep[i] = 1
        