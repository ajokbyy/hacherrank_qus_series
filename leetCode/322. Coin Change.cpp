------------------------------------------------------***----------------------------------------------------------------------------------
  322. Coin Change
Solved
Medium
Topics
premium lock icon
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
  ----------------------------------------------------------------------****--------------------------------------------------------------------
  Ans - 
  class Solution {
public:
    int n;
    int t[301][10001]; // amount up to 10^4

    int solve(int i, vector<int>& coins, int amount) {
        if (amount == 0) return 0; // 0 coins needed
        if (i == n || amount < 0) return 1e9; // impossible path

        if (t[i][amount] != -1) return t[i][amount];

        // Option 1: take coin[i]
        int take = 1 + solve(i, coins, amount - coins[i]);

        // Option 2: skip coin[i]
        int skip = solve(i + 1, coins, amount);

        return t[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(t, -1, sizeof(t));
        int res = solve(0, coins, amount);
        return (res >= 1e9) ? -1 : res;
    }
};
