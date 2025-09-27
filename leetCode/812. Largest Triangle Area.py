# 812. Largest Triangle Area
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

 

# Example 1:


# Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
# Output: 2.00000
# Explanation: The five points are shown in the above figure. The red triangle is the largest.
# Example 2:

# Input: points = [[1,0],[0,0],[0,1]]
# Output: 0.50000
 

# Constraints:

# 3 <= points.length <= 50
# -50 <= xi, yi <= 50
# All the given points are unique.
 

# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 104,334/155K
# Acceptance Rate
# 67.3%
# Topics
# Array
# Math
# Geometry
# Weekly Contest 79

# ----------------------------------------------------------------------------
# complixty - o(n^3)
class Solution(object):
    def largestTriangleArea(self, points):
        def area(A, B, C):
            x1,y1 = A; x2,y2 = B; x3,y3 = C
            cross = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)
            return abs(cross) * 0.5

        n = len(points)
        best = 0.0
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    best = max(best, area(points[i], points[j], points[k]))
        return best
        """
        :type points: List[List[int]]
        :rtype: float
        """
        
        
