# 88. Merge Sorted Array
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Hint
# You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

# Merge nums1 and nums2 into a single array sorted in non-decreasing order.

# The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

# Example 1:

# Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
# Output: [1,2,2,3,5,6]
# Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
# The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
# Example 2:

# Input: nums1 = [1], m = 1, nums2 = [], n = 0
# Output: [1]
# Explanation: The arrays we are merging are [1] and [].
# The result of the merge is [1].
# Example 3:

# Input: nums1 = [0], m = 0, nums2 = [1], n = 1
# Output: [1]
# Explanation: The arrays we are merging are [] and [1].
# The result of the merge is [1].
# Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

# Constraints:

# nums1.length == m + n
# nums2.length == n
# 0 <= m, n <= 200
# 1 <= m + n <= 200
# -109 <= nums1[i], nums2[j] <= 109
 

# Follow up: Can you come up with an algorithm that runs in O(m + n) time?

 
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 5,166,225/9.6M
# Acceptance Rate
# 53.8%
# Topics
# Array
# Two Pointers
# Sorting




# _______________________________________________________________________***__________________________________________________________________________________________________________________________________



class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # here it was given that the first arr which is nums1 is containg sufficent amount of 
        # storage to care both nums1 and nums2
        # So the Brute force method is making one new array = (temp) and than adding all
        # value of num1 and num2 init and then storing that value in nums1(and also removing zeroors.)
        # So we are going to use two pointer to compair the lasgest value of nums2 with nums1 and than add it in nums1 section

        #last index of nums1 
        # m and n are the size for the lists
        last = m + n - 1
        while m > 0 and n > 0:

            # Now we are mergeing all the list in nums1 in reverse order

            if nums1[m-1] > nums2[n-1]:
                nums1[last] = nums1[m-1]
                m -= 1
            else:
                nums1[last] = nums2[n-1]
                n-=1
            last-= 1
        # edge case the last elemnet if we live it it will create peobleam 
        while n > 0:
            nums1[last] = nums2[n - 1]
            n , last = n - 1, last - 1




# ___________________________________***_____________________________________________
# line by line explanation 
# Line-by-line explanation

# last = m + n - 1

# Compute the index of the last position in nums1 where an element should be placed after the merge.

# If nums1 should contain all m + n elements, the final index is (m + n) - 1 (zero-based indexing).

# while m > 0 and n > 0:

# Loop while both arrays still have unprocessed elements.

# m and n represent the counts of remaining valid elements in nums1 and nums2 respectively. When either becomes 0, this loop stops.

# (comment) # Now we are merging both lists into nums1 in reverse order

# Explains the strategy: place the largest remaining element at nums1[last], then move last backward. Merging backward prevents overwriting the unprocessed portion of nums1.

# if nums1[m - 1] > nums2[n - 1]:

# Compare the last unmerged elements of each array:

# nums1[m - 1] is the last valid element currently in nums1.

# nums2[n - 1] is the last unmerged element in nums2.

# If nums1's last element is larger, it should go at the current last position.

# nums1[last] = nums1[m - 1]

# Place the larger element (nums1[m-1]) into position last of nums1.

# m -= 1

# We used up that element from nums1, so decrement the count m (now one fewer element remains to consider in nums1).

# else:

# If nums2[n - 1] >= nums1[m - 1] (i.e., nums2's current last is larger or equal), we place nums2's element into nums1[last].

# nums1[last] = nums2[n - 1]

# Copy the element from nums2 into nums1 at index last.

# n -= 1

# Decrement n because we consumed an element from nums2.

# last -= 1

# Move the target last position left by one — next iteration will fill the previous index.

# (comment) # Edge case: if any elements remain in nums2, copy them

# After the main loop finishes, one of the arrays may still have unprocessed elements. If nums1 still has leftover elements, they're already in correct place (because we merged from the back). But if nums2 still has elements, they must be copied into the front of nums1.

# while n > 0:

# Loop while nums2 still has elements left to copy.

# nums1[last] = nums2[n - 1]

# Copy the last remaining element of nums2 into nums1 at index last.

# n, last = n - 1, last - 1

# Decrement both n and last in a single line (tuple assignment). Equivalent to:

# n -= 1
# last -= 1
