/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// recursion
// Runtime: 0 ms, faster than 100.00% of C online submissions for Invert Binary Tree.
// Memory Usage: 6.1 MB, less than 30.89% of C online submissions for Invert Binary Tree.
void invert_tree_x(struct TreeNode* root)
{
    if (root == NULL) return;
    struct TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left != NULL) invert_tree_x(root->left);
    if (root->right != NULL) invert_tree_x(root->right);

}
struct TreeNode* invertTree(struct TreeNode* root){
    invert_tree_x(root);
    return root;
}