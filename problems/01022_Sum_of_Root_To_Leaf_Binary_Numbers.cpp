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
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        if (root == NULL) {
            return 0;
        }
        dfs_sum_root_to_leaf(0, root, &result);
        return result;

    }
    void dfs_sum_root_to_leaf(int sum, TreeNode *root, int *result)
    {
        if (root == NULL) return;
        sum = (sum << 1) + root->val;
        if ((root->left == NULL) && (root->right == NULL)) {
            *result = *result + sum;
            return;
        }
        dfs_sum_root_to_leaf(sum, root->left, result);
        dfs_sum_root_to_leaf(sum, root->right, result);
        return;
    }
};