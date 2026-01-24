class Solution:
    def firstUniqChar(self, s: str) -> int:
        has = {}

        # Step 1: Count frequency
        for ch in s:
            if ch in has:
                has[ch] += 1
            else:
                has[ch] = 1

        # Step 2: Find first unique character
        for i in range(len(s)):
            if has[s[i]] == 1:
                return i

        return -1
