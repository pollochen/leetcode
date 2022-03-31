/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Runtime: 4 ms, faster than 92.65% of C online submissions for Path Sum.
// Memory Usage: 8.3 MB, less than 34.83% of C online submissions for Path Sum.
bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) return false;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL) {
        if (targetSum == 0) {
            return true;
        }else {
            return false;
        }
    }
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}