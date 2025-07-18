--------------------------------------------------------------***---------------------------------------------------------------------------------------------
45. Jump Game II
Solved
Medium
Topics
premium lock icon
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
---------------------------------------------------------------***------------------------------------------------------------------------------------
Ans ->
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, INT_MAX);//we are assuming that it will take infinit step to reach the last position

        //dp[i] // min jumps from index[start] to n-1 index
        dp[n-1] = 0;
        for(int start= n-2; start>=0; --start){
            int maxStapsAllowed = nums[start];
            int minstep = INT_MAX;
            //we are comparing with the max number here 

            for(int jump = 1; jump <= maxStapsAllowed && jump + start < n; jump++){
                minstep= min(minstep, dp[start + jump]);
            }
            if(minstep == INT_MAX){
                dp[start] = INT_MAX;
            }else{
                dp[start] = minstep+1;
            }
        }
        return dp[0];
    }
};
