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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode *> stk;

        if (root == NULL) {
            return 0;
        }

        // the result of inorder traverse is a sorted list
        int val_pre = -1;
        int result = INT_MAX;
        TreeNode* node_cur = root;
        while (node_cur != NULL || stk.empty() == false) {
            if (node_cur != NULL) {
                // node is available
                // 1. push current node
                stk.push(node_cur);
                // 2. traverse left node
                node_cur = node_cur->left;
            } else {
                // node is not available
                // 1. pop one node
                node_cur = stk.top();
                stk.pop();
                //result.push_back(node_cur->val);
                if (val_pre == -1) val_pre = node_cur->val;
                else {
                    result = min(result, node_cur->val - val_pre);
                    val_pre = node_cur->val;
                }

                // 2. traverse right node
                node_cur = node_cur->right;
            }
        }
        return result;
    }
};