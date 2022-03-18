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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode *> queue;

        int result = 0;
        queue.push(root);
        while (queue.empty() == false) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front(); queue.pop();

                if ((node->left != NULL) && (node->left->left == NULL) && (node->left->right == NULL) ) {
                    result += node->left->val;
                }

                if (node->left != NULL) queue.push(node->left);
                if (node->right != NULL) queue.push(node->right);
            }
        }
        return result;
    }
};