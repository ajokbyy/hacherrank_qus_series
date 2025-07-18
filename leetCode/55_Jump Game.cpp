----------------------------------------------------------***-------------------------------------------------------------------------
  55. Jump Game
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
  ---------------------------------------------------------------------------****---------------------------------------------------------------------
  class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<bool> dp(n, false);
        dp[n-1] = true;
        for(int startindex = n-2; startindex>= 0; --startindex){
            int maxjumpsAllowed = nums[startindex];
            bool ispossibleToReach = false;
            for(int jump = 1; jump<=maxjumpsAllowed; jump++){
                if(dp[startindex + jump] == true){
                    ispossibleToReach = true;
                    break;
                }
            }
            dp[startindex] = ispossibleToReach;
        }
        
        return dp[0];

    }
};


// int n = nums.size()-1;
        // vector<int> dp(n+1, -1);

        // if(nums.length()==0){
        //     return true;
        // }
        // for(int i=n-2; i<=n; i++){
        //     if()

        // }
        // return dp[0];
