------------------------------------------------------------***-----------------------------------------------------------------------------------------
  21. Merge Two Sorted Lists
Solved
Easy
Topics
premium lock icon
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
  ---------------------------------------------------------------------***--------------------------------------------------------------------------------------


  class Solution {
public:
    // Function to merge two sorted linked lists recursively
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // BASE CASE: If either list is empty, return the other list
        if (list1 == NULL || list2 == NULL) {
            return list1 == NULL ? list2 : list1;
            // If list1 is NULL, return list2; else return list1
        }

        // If current node of list1 is smaller or equal, choose list1
        if (list1->val <= list2->val) {
            // Recursively merge the rest of list1 and list2
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
            // Return list1 as the smaller head
        } 
        else {
            // Else, choose list2 (as it has the smaller value)
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
            // Return list2 as the smaller head
        }
    }
};
