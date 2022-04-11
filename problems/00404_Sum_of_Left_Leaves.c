/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Runtime: 2 ms, faster than 65.12% of C online submissions for Sum of Left Leaves.
// Memory Usage: 6.4 MB, less than 37.21% of C online submissions for Sum of Left Leaves.
void inorder_dfs(struct TreeNode* root, bool is_left, int *result)
{
    if (root == NULL) return;
    inorder_dfs(root->left, true, result);
    if (root->left == NULL && root->right == NULL && is_left == true) {
        *result += root->val;
    }
    inorder_dfs(root->right, false, result);
}
int sumOfLeftLeaves(struct TreeNode* root){
    int result = 0;
    inorder_dfs(root, false, &result);
    return result;
}