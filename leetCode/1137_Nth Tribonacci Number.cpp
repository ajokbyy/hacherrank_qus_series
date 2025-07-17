---------------------------------------------------***------------------------------------------------------------------------------------------
  1137. N-th Tribonacci Number
Solved
Easy
Topics
premium lock icon
Companies
Hint
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 

Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
  ---------------------------------------------------------------------------***------------------------------------------------------------------
  ans - >
  class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

       vector<int> dp(n+1);
    //    dp[n-1] = dp[n] = 1;
    // the value of 0, 1, and 2 is already given 
       dp[0] = 0;
       dp[1] = 1;
       dp[2] = 1;
    // here we are using Dp(dynamic programm ) to find the Nth Tribonacci number by adding last 3 number to the new number and sturing them in vector 
       for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
       }
       return dp[n];
// here we are returing the last value whivh was asket by the problem
    }
};
