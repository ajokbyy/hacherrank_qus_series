// Parenthesis Checker
// Difficulty: EasyAccuracy: 28.56%Submissions: 671K+Points: 2
// Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
// An input string is valid if:

//          1. Open brackets must be closed by the same type of brackets.
//          2. Open brackets must be closed in the correct order.

// Examples :

// Input: s = "[{()}]"
// Output: true
// Explanation: All the brackets are well-formed.
// Input: s = "[()()]{}"
// Output: true
// Explanation: All the brackets are well-formed.
// Input: s = "([]"
// Output: False
// Explanation: The expression is not balanced as there is a missing ')' at the end.
// Input: s = "([{]})"
// Output: False
// Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.
// Constraints:
// 1 ≤ s.size() ≤ 106
// s[i] ∈ {'{', '}', '(', ')', '[', ']'}

// Expected Complexities
// Company Tags
// FlipkartAmazonMicrosoftOYO RoomsSnapdealOracleWalmartAdobeGoogleYatra.com

// ------------------------------------------------*****----------------------------------------------------------------------------

class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char> ans;
        for(char ch:k){
            if(ch == '(' || ch =='{' || ch=='['){
                ans.push(ch);
            }
            else{
                if(ans.empty()||
                (ch == ')' && ans.top() != '(')||
                (ch == '}' && ans.top() != '{') ||
                (ch==']' && ans.top() != '[')){
                    return false;
                } 
                ans.pop();
            }
            
        }
        return ans.empty();
      
    }
    
};
