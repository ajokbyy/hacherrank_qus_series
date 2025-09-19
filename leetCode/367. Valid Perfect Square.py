367. Valid Perfect Square
Solved
Easy
Topics
premium lock icon
Companies
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
 

Constraints:

1 <= num <= 231 - 1
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
822,575/1.9M
Acceptance Rate
44.4%
Topics
Math
Binary Search
--------------------------------------------------------------
class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 2:
            return True

        r = num
        while r * r > num:
            r = (r + num // r) // 2
        return r * r == num
        
