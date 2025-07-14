// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

// ---------------------------------------------------------------------****-------------------------------------------------------------------------------
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
    TreeNode* buildTreeHelper(
        const vector<int>& preorder, const vector<int>& inorder,
        int preStart, int preEnd,
        int inStart, int inEnd,
        unordered_map<int, int>& inMap) {

        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        int inRootIndex = inMap[rootVal];
        int leftTreeSize = inRootIndex - inStart;

        root->left = buildTreeHelper(preorder, inorder,
                                     preStart + 1, preStart + leftTreeSize,
                                     inStart, inRootIndex - 1,
                                     inMap);

        root->right = buildTreeHelper(preorder, inorder,
                                      preStart + leftTreeSize + 1, preEnd,
                                      inRootIndex + 1, inEnd,
                                      inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, inorder, 0, n - 1, 0, n - 1, inMap);
    }
};
