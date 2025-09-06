14. Longest Common Prefix
Solved
Easy
Topics
premium lock icon
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
  --------------------------------------------------------------------------------------------
  class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string prefix = strs[0] ;
        for(int i=1; i<strs.size(); i++){
            while(strs[i].find(prefix)!= 0){
                prefix = prefix.substr(0, prefix.size()-1);
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

---------------------------------------------------------------------
  Complexity

Time: O(N × M) where

N = number of strings,

M = length of the shortest string.

Space: O(1) (we only store the prefix).
--------------------------------------------------------------
  expl- 
  Step 1: strs[i].find(prefix) != 0

find(prefix) returns the index of the first occurrence of prefix inside strs[i].

If prefix is a prefix of the string, then its position = 0.

If not, result is not 0 (or even npos if not found at all).

👉 So, this condition checks:

“Is prefix NOT at the very beginning of strs[i]?”

Step 2: prefix = prefix.substr(0, prefix.size() - 1);

If the current prefix is not a prefix of strs[i],
→ shrink prefix by removing its last character.

substr(0, prefix.size() - 1) takes a substring from index 0 up to prefix.size()-2.
  -----------------------------------------------------------------------------------------------------------------------------------------
