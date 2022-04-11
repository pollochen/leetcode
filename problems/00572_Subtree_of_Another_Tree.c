// https://leetcode.com/problems/subtree-of-another-tree/discuss/1919210/C%2B%2B-solution-or-just-like-same-tree-problem
// Runtime: 27 ms, faster than 27.00% of C online submissions for Subtree of Another Tree.
// Memory Usage: 10.9 MB, less than 99.50% of C online submissions for Subtree of Another Tree.
// check if 2 tree is identical
bool is_identical(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL && subRoot == NULL) return true;
    if (root == NULL || subRoot == NULL) return false;
    // no NULL for both here
    if (root->val != subRoot->val) return false;
    return is_identical(root->left, subRoot->left) && is_identical(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot){
    if (root == NULL) return false;
    if ((root->val == subRoot->val) && is_identical(root, subRoot)) {
        // if root value is identical && tree is identical
        return true;
    } else {
        // try left and right tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
}