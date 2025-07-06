// 128. Longest Consecutive Sequence
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3
 // ----------------------------------****------------------------------------------
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());     // 6
        int longest = 0;                                    // 7
        
        for (int x : s) {                                   // 8
            if (s.count(x - 1)) continue;                   // 9
            
            int currentLen = 1;                             // 10
            int currentNum = x + 1;                         // 11
            while (s.count(currentNum)) {                   // 12
                ++currentLen;                               // 13
                ++currentNum;                               // 14
            }                                               // 15
            longest = max(longest, currentLen);             // 16
        }                                                   // 17
        return longest;
    }
};

// Constraints:

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
