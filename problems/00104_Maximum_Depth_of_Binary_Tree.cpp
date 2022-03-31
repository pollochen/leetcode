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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// recursion
// Runtime: 13 ms, faster than 44.59% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.1 MB, less than 14.49% of C++ online submissions for Maximum Depth of Binary Tree.
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1; // depth includes itself
        int depth = 0;
        if (root->left != NULL) depth = 1 + maxDepth(root->left);
        if (root->right != NULL) depth = max(depth, 1 + maxDepth(root->right));
        return depth;
    }
};