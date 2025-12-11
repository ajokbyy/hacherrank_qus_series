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
        