// 110. Balanced Binary Tree
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given a binary tree, determine if it is height-balanced.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104
// -------------------------------------------------------*****-------------------------------------------------------------------
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
    pair<int, bool> isBalancedHelper(TreeNode* root){
        if(root==NULL){
            return{0, true};
        }
        pair<int, bool> leftInfo = isBalancedHelper(root->left);
        pair<int, bool> rightInfo = isBalancedHelper(root->right);
        bool iscurrTreeBalanced = leftInfo.second == true && rightInfo.second == true &&
                                    abs(leftInfo.first - rightInfo.first) <=1;
        int currTreeHeight = max(leftInfo.first, rightInfo.first) +1;
        return{currTreeHeight, iscurrTreeBalanced};

    }
    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root).second;
    }
};
