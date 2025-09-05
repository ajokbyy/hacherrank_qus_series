203. Remove Linked List Elements
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50





  -----------------------------------------------------------------------------------------------------------------------------------------------------
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
    ListNode* removeElements(ListNode* head, int val) {
        // Move head while the head node itself needs removal
        while (head != nullptr && head->val == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->next->val == val) {
                ListNode* toDelete = current->next;
                current->next = current->next->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
        return head;
        // if(head == NULL){
        //     return NULL;
        // }
        // ListNode* curr = head;

        // while(curr != NULL){
        //     if((curr->next != NULL) && (curr->val == curr->next->val)){
        //         ListNode* next_next = curr->next->next;
        //         ListNode* todel = curr->next;
        //         delete(todel);
        //         curr->next = next_next;
        //     } 
        //     else{
        //         curr=curr->next;
        //     }
        // }
        // return head;
    }
};


---------------------------------------------------same code using recursion----------------
 class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        
        // Recursively process the next node
        head->next = removeElements(head->next, val);
        
        // If current node's value equals val, skip it
        if (head->val == val) {
            ListNode* temp = head->next;
            delete head;  // Free the current node
            return temp;
        } else {
            return head;
        }
    }
};
