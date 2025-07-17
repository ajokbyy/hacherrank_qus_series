------------------------------------------------------***---------------------------------------------
  70. Climbing Stairs
Attempted
Easy
Topics
premium lock icon
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
  ------------------------------------------------------------***----------------------------------------------------------------------------
  ans -> -------------------------m1--------------------------------
  class Solution {
public:
    int climbStairsHelper(int end, vector<int>& dp) {
        if (end == 1 ||end == 0) {
            return 1;
        }
        if(dp[end] != -1){
            return dp[end];
        }
        dp[end] = climbStairsHelper(end-1, dp)+climbStairsHelper(end-2, dp);
        return dp[end];
    }
    int climbStairs(int n) { 
        vector<int> dp(n+1, -1);
        // dp[n] = 1;

        return climbStairsHelper(n, dp);
          }
};
// ----------------------------------method 1 -----------------------------------------------------
// class Solution {
// public:
//     int climbStairsHelper(int end) {
//         if (end == 1) {
//             return 1;
//         } else if (end == 0) {
//             return 0;
//         } else {
//             return climbStairsHelper(end - 1) + climbStairsHelper(end - 2);
//         }
//     }
//     int climbStairs(int n) { return climbStairsHelper(n+1); }
// };
