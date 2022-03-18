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
    bool result = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return result;
    }
    void dfs(TreeNode *node, int sum)
    {
        if (node == NULL) return;
        if ((node->left == NULL) && (node->right == NULL) && (node->val == sum)) {
            result = true;
            return;
        }
        
        if (node->left != NULL) dfs(node->left, sum - node->val);
        if (node->right != NULL) dfs(node->right, sum - node->val);
    }
};