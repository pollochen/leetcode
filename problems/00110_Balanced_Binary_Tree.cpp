// https://www.cnblogs.com/grandyang/p/4045660.html
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
    int tree_depth(TreeNode *node) {
        if (node == NULL) return 0;
        return 1 + max(tree_depth(node->left), tree_depth(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        if (abs(tree_depth(root->left) - tree_depth(root->right)) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};