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
    int result = 0;
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, true, 0);
        maxZigZag(root, false, 0);
        return result;
    }
private:
    void maxZigZag(TreeNode *root, bool isLeftNext, int steps) {
        if (root == NULL) return;
        result = max(steps, result);
        if (isLeftNext == true) {
            // go to left or re-start from right
            maxZigZag(root->left, false, steps+1);
            maxZigZag(root->right, true, 1);
        } else {
            // go to right or re-start from left
            maxZigZag(root->right, true, steps+1);
            maxZigZag(root->left, false, 1);
        }
    }
};