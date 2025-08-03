------------------------------------------***----------------------------------------------------------------------------------------------
  2. Add Two Numbers
Solved
Medium
Topics
premium lock icon
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
---------------------------------------------------------***-------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node acts as the starting point of the result linked list.
        ListNode* dummy = new ListNode(0);
        
        // 'current' will be used to build the result list.
        ListNode* current = dummy;

        // This will store the carry from the addition of two digits.
        int carry = 0;

        // Loop until both lists are exhausted and no carry remains.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            // Extract values from the current nodes of l1 and l2 if available.
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of digits plus the carry.
            int sum = x + y + carry;

            // Update carry for the next iteration (e.g., sum = 15 → carry = 1).
            carry = sum / 10;

            // Create a new node with the single digit of sum (e.g., sum = 15 → node = 5).
            current->next = new ListNode(sum % 10);

            // Move the current pointer forward in the result list.
            current = current->next;

            // Advance input lists if not null.
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the next node of dummy, which is the actual head of the result list.
        return dummy->next;
    }
};
--------------------------------------------------------------***---------------------------------------------------------------------------------
