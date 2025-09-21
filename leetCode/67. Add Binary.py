# 67. Add Binary
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Given two binary strings a and b, return their sum as a binary string.

 

# Example 1:

# Input: a = "11", b = "1"
# Output: "100"
# Example 2:

# Input: a = "1010", b = "1011"
# Output: "10101"
 

# Constraints:

# 1 <= a.length, b.length <= 104
# a and b consist only of '0' or '1' characters.
# Each string does not contain leading zeros except for the zero itself.
 

# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 1,991,154/3.5M
# Acceptance Rate
# 56.1%
# Topics
# Math
# String
# Bit Manipulation
# Simulation
# --------------------------------------------------------------------------------------------------------------------------------
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        num1 = int(a, 2)
        num2 = int(b, 2)
        
        # Add them
        total = num1 + num2
        
        # Convert back to binary string (remove '0b' prefix)
        return bin(total)[2:]

# ---------------------------------------------------------------------------------------------------
# #include <bits/stdc++.h>
# using namespace std;

# class Solution {
# public:
#     string addBinary(string a, string b) {
#         int i = a.size() - 1;
#         int j = b.size() - 1;
#         int carry = 0;
#         string result = "";

#         while (i >= 0 || j >= 0 || carry) {
#             int total = carry;
#             if (i >= 0) total += a[i--] - '0'; // convert char to int
#             if (j >= 0) total += b[j--] - '0';

#             result.push_back((total % 2) + '0'); // append current bit
#             carry = total / 2;                  // update carry
#         }

#         reverse(result.begin(), result.end());
#         return result;
#     }
# };
