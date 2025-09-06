58. Length of Last Word
Solved
Easy
Topics
premium lock icon
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.
 
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,949,539/5.2M
Acceptance Rate
57.0%
Topics
String
------------------------------------------------------------------------------------------------explanation
  ✅ Approach

step 1 .Start from the end of the string.

step 2 .Skip trailing spaces. // step 2 explanation -> i starts from the last index of the string (s.length() - 1).

// The loop runs as long as:

// i >= 0 → we don’t go out of bounds.

// s[i] == ' ' → the character at index i is a space.

// Inside the loop:
// i-- → move one step left.

step 3 .Count characters until you hit another space (or the start of the string).

step 4 .That count = answer.

--------------------------------------------------------------------------------------code
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;// starting from the end
        int length=0;
        while(i>= 0 && s[i] == ' '){// skip the space
            i--;
        }
        while(i>=0 && s[i] != ' '){
            length ++;
            i--;
        }
        return length;
    }
};
