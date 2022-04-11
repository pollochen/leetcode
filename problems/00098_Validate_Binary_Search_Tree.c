/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// inorder recursion with value check
// Runtime: 16 ms, faster than 15.68% of C online submissions for Validate Binary Search Tree.
// Memory Usage: 8.7 MB, less than 80.31% of C online submissions for Validate Binary Search Tree.
bool inorder_check(struct TreeNode* root, long *num)
{
    if (root == NULL) return true;
    if (inorder_check(root->left, num) == false) return false;
    if (*num == 0x7FFFFFFFF) {
        // initial value
        *num = root->val;
    } else {
        // check if the value we want to push is larger than previous pushed
        // 2 nodes can't have same value in BST
        if (*num >= root->val) return false;
        else *num = root->val;
    }
    return inorder_check(root->right, num);
}

bool isValidBST(struct TreeNode* root){
    long num = 0x7FFFFFFFF;
    return inorder_check(root, &num);
}