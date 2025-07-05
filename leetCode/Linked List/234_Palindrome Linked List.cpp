// 234. Palindrome Linked List
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false
 

// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9


// -------------------------------------***********_-------------------------------------
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // -------------------------------
        // 1. Find the middle (slow) using fast/slow pointers
        // -------------------------------
        ListNode* slow = head;   // moves 1 step
        ListNode* fast = head;   // moves 2 steps
        while (fast != NULL && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // -------------------------------
        // 2. Skip the middle node for odd lengths
        //    (fast is non‑null only when length is odd)
        // -------------------------------
        if (fast != NULL ){    // true only for odd‑length lists
            slow = slow->next; }
        // -------------------------------
        // 3. Reverse the second half of the list
        // -------------------------------
        ListNode* prev = nullptr;           // new head of reversed part
        while (slow!=NULL) {
            ListNode* nextNode = slow->next;
            slow->next = prev;              // flip pointer
            prev = slow;                    // advance prev
            slow = nextNode;                // advance slow
        }
        // Now 'prev' is the first node of the reversed right half.

        // -------------------------------
        // 4. Compare the two halves
        // -------------------------------
        ListNode* left  = head;   // start of left half
        ListNode* right = prev;   // start of reversed right half
        while (right>=left) {           // right half is never longer than left
            if (left->val != right->val) return false;
            left  = left->next;
            right = right->next;
        }
        return true;              // all pairs matched!
    }

};
