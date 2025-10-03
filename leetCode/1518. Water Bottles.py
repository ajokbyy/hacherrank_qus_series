# 1518. Water Bottles
# 1518. Water Bottles
# Solved
# Easy
# Topics
# premium lock icon
# Companies
# Hint
# There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

# The operation of drinking a full water bottle turns it into an empty bottle.

# Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

# Example 1:


# Input: numBottles = 9, numExchange = 3
# Output: 13
# Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
# Number of water bottles you can drink: 9 + 3 + 1 = 13.
# Example 2:


# Input: numBottles = 15, numExchange = 4
# Output: 19
# Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
# Number of water bottles you can drink: 15 + 3 + 1 = 19.
 

# Constraints:

# 1 <= numBottles <= 100
# 2 <= numExchange <= 100
 
# Seen this question in a real interview before?
# 1/5
# Yes
# No
# Accepted
# 399,526/549.3K
# Acceptance Rate
# 72.7%
# Topics
# Math
# Simulation
# Weekly Contest 198

# -----------------------------------------------------------------------------------------------
class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        total = numBottles  # already full bottles
        empty = numBottles  # after drinking

        while empty >= numExchange:
            new_bottles = empty // numExchange
            total += new_bottles
            empty = empty % numExchange + new_bottles  # leftover + new full become empty later

        return total
        
