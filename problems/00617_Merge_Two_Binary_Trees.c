/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// recursion
// Runtime: 45 ms, faster than 33.71% of C online submissions for Merge Two Binary Trees.
// Memory Usage: 14.5 MB, less than 43.54% of C online submissions for Merge Two Binary Trees.
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    if (root1 == NULL) return root2;
    if (root2 == NULL) return root1;

    // going here means root1 and root2 are not NULL
    root1->val += root2->val;
    // merge left nodes in root1 and root2
    root1->left  = mergeTrees(root1->left, root2->left);
    // merge right nodes in root1 and root2
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
}