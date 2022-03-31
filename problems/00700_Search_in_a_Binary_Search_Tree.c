/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Runtime: 41 ms, faster than 25.14% of C online submissions for Search in a Binary Search Tree.
// Memory Usage: 15.1 MB, less than 68.99% of C online submissions for Search in a Binary Search Tree.
struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode *result = NULL;
    while (root != NULL) {
        if (root->val == val) {
            result = root;
            break;
        }
        if (val > root->val) {
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return result;
}