// 144. Binary Tree Preorder Traversal
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]

// Output: [1,2,3]

// Explanation:



// Example 2:

// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

// Output: [1,2,4,5,6,7,3,8,9]

// Explanation:



// Example 3:

// Input: root = []

// Output: []

// Example 4:

// Input: root = [1]

// Output: [1]

 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 // -------------------------------------------------******--------------------------------------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void preorderhelper(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;
        ans.push_back(root->val);
        preorderhelper(root->left, ans);
        preorderhelper(root->right, ans);
    }
    // void inorderhelper(TreeNode* root, vector<int>& ans) {
    //     if (root == nullptr)
    //         return;
    //     preorderhelper(root->left, ans);
    //     ans.push_back(root->val);
    //     preorderhelper(root->right, ans);
    // }
    // void postorderhelper(TreeNode* root, vector<int>& ans) {
    //     if (root == nullptr)
    //         return;
    //     preorderhelper(root->left, ans);
    //     preorderhelper(root->right, ans);
    //     ans.push_back(root->val);
    // }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorderhelper(root, ans);
        return ans;
    }
    
};
