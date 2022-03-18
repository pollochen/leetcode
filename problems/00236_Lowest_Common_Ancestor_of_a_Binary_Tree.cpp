// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* result;
    bool lca_dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL) {
            return false;
        }
        bool flag_left = lca_dfs(root->left, p, q); // find if p or q is in left node
        bool flag_center = 0;
        if ((root == p) || (root == q)) { // find if p or q is in this node
            flag_center = 1;
        }
        bool flag_right = lca_dfs(root->right, p, q); // find if p or q is in right node
        int count = 0;
        if (flag_left == true) count++;
        if (flag_right == true) count++;
        if (flag_center == true) count++;
        if (count >= 2) {
            this->result = root;
        }
        return count > 0? true: false;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = NULL;
        lca_dfs(root, p, q);
        return result;
    }
};