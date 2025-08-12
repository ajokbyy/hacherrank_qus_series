19. Remove Nth Node From End of List
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

  ----------------------------------------------------------***----------------------------------------------------------
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node before head to handle edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast pointer n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both fast and slow until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the target node
        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy->next;
    }
};

// Time Complexity:
// O(L), where L is the length of the linked list.

// Space Complexity:
// O(1) — We only use constant extra space.

---------------------------------------------------------***-----------------------------------------------------------------
