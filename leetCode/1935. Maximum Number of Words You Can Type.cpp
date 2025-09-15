1935. Maximum Number of Words You Can Type
Solved
Easy
Topics
premium lock icon
Companies
Hint
There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

 

Example 1:

Input: text = "hello world", brokenLetters = "ad"
Output: 1
Explanation: We cannot type "world" because the 'd' key is broken.
Example 2:

Input: text = "leet code", brokenLetters = "lt"
Output: 1
Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
Example 3:

Input: text = "leet code", brokenLetters = "e"
Output: 0
Explanation: We cannot type either word because the 'e' key is broken.
 

Constraints:

1 <= text.length <= 104
0 <= brokenLetters.length <= 26
text consists of words separated by a single space without any leading or trailing spaces.
Each word only consists of lowercase English letters.
brokenLetters consists of distinct lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
180,035/218.9K
Acceptance Rate
82.3%
Topics
Hash Table
String
Weekly Contest 250
-----------------------------------------------------------------------------------------------------

  class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        stringstream ss(text);
        string word;
        int count = 0;

        while (ss >> word) {
            bool canType = true;
            for (char c : word) {
                if (broken.count(c)) {
                    canType = false;
                    break;
                }
            }
            if (canType) count++;
        }
        return count;
    }
};



// -------------------------
// class Solution:
//     def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
//         broken = set(brokenLetters)
//         count = 0
        
//         for word in text.split():
//             if not any(ch in broken for ch in word):
//                 count += 1
                
//         return count
