/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// dfs recursion with max()
// Runtime: 10 ms, faster than 28.68% of C online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 8.1 MB, less than 37.43% of C online submissions for Maximum Depth of Binary Tree.
int max_int(int x, int y)
{
    if (x > y) return x;
    else return y;
}

int maxDepth(struct TreeNode* root){
    if (root == NULL) return 0;
    return max_int(1 + maxDepth(root->left), 1+maxDepth(root->right));
}