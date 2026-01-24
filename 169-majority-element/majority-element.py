class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        hep ={}
        n = len(nums)
        for i in nums:
            if i in hep:
                hep[i] += 1
            else:
                hep[i] = 1

        for i in hep:
            if hep[i] > n//2:
                return i 
        