// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
// Memory Usage: 16.5 MB, less than 42.22% of C++ online submissions for Symmetric Tree.
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return dfs_symmetric(root->left, root->right);
    }

    bool dfs_symmetric(TreeNode *nodeLeft, TreeNode *nodeRight) {
        if (nodeLeft == NULL && nodeRight == NULL) {
            return true;
        }
        if (nodeLeft == NULL || nodeRight == NULL) {
            return false;
        }
        if (nodeLeft->val != nodeRight->val) {
            return false;
        }
        return dfs_symmetric(nodeLeft->left, nodeRight->right) && dfs_symmetric(nodeLeft->right, nodeRight->left);
    }
};