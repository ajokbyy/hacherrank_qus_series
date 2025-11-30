class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:

        total = sum(nums)
        target = total % p
        
        if target == 0:
            return 0  # Already divisible
        
        prefix = 0
        hashmap = {0: -1}  # prefix mod value → index
        ans = len(nums)
        
        for i, num in enumerate(nums):
            prefix = (prefix + num) % p
            
            # We need prefix[j] = (prefix - target + p) % p
            needed = (prefix - target) % p
            
            if needed in hashmap:
                ans = min(ans, i - hashmap[needed])
            
            hashmap[prefix] = i
        
        return ans if ans < len(nums) else -1
        