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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        if (p->val > val && q->val > val) { // p and q > node
            return lowestCommonAncestor(root->right, p, q);
        }
        if (p->val < val && q->val < val) { // p and q < node
            return lowestCommonAncestor(root->left, p, q);
        }

        return root;
    }
};