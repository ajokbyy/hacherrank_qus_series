class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        max_area = 0

        while l < r:
            width = r - l
            area = width * min(height[l], height[r])
            max_area = max(max_area, area)

        # Move the smaller height pointer
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return max_area