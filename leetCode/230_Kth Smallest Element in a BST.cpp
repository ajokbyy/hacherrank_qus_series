-----------------------------------------------------------***--------------------------------------------------------------------------------------------------
  230. Kth Smallest Element in a BST
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
  ------------------------------------------------------------------------***------------------------------------------------------------------------------
  Ans - 
  /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void inorderhelper(TreeNode* root, vector<int>& ans) {//we are giving the funtion a root value and a vector Know as "ans" & - sign means we are using a raferance value - means we are ching the orignial "ans" veter
//we have maken "ans" vector in our main funtion
        if (root == nullptr)
            return;
            //here we are cheking if our tree is empty or not
        inorderhelper(root->left, ans);//we are telling it to go to the left side of tree sirst
        ans.push_back(root->val);//ther to store the root element in the "ans" vecter or we can say that push the root value to the ans vecter
        inorderhelper(root->right, ans);//then again go to the reight side of the tree to continu the process until it complet the whole tree
    }
int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;//here we are making the vector - "ans"
        inorderhelper(root, ans);
        return(ans[k-1]);//we have to find the kth element - and vector/array is stating from 0 index so we have to -1 from the original k = value;
        //for example k = 3 so index = 0,1,2,3 - it value is in the 2 - index.
       
    }

};
