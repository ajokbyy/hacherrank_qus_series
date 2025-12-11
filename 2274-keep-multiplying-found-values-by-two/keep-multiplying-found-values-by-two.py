class Solution:
    def findFinalValue(self, nums: List[int], original: int) -> int:
        while True:
            found = False
            for i in nums:
                if i==original:
                    original = 2 * original
                    found = True
                    break
            if not found:
                return original
        

# Optimal Approcah - we are using map set funtions here
# fistly we are keeping every elemnet of nums in set
#and then find which one is the original 
# s = set(nums)
# while original in s:
#     original *= 2
# return original