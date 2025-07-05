// 3. Longest Substring Without Repeating Characters
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

// --------------------------------------------------------------*******---------------------------------------------
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> frequency;
        int maxi = 0;
        int left = 0;
        int right = 0;
        while (right<s.size()){
            frequency[s[right]] += 1;
            while(frequency[s[right]] > 1){
                frequency[s[left]] -= 1;
                left++;
            }
            int size = right - left + 1;
            maxi = max(maxi, size);
            right ++;

        }
        return maxi;
    }
};
