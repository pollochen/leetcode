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
    TreeNode *flatten_dfs(TreeNode *root) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) return root;

        TreeNode *last = root;
        // process left node
        if (root->left != NULL) {
            last = flatten_dfs(root->left);
            // hook root->right to last->right
            last->right = root->right;
            // asign root->left to root->right
            root->right = root->left;
            // set root->left as NULL
            root->left = NULL;
        }

        // process right node
        if (last->right != NULL) {
            last = flatten_dfs(last->right);
        }
        return last;
    }
    void flatten(TreeNode* root) {
        flatten_dfs(root);
    }
};