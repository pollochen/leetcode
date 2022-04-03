/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// recursion
// Runtime: 91 ms, faster than 5.93% of C online submissions for Lowest Common Ancestor of a Binary Search Tree.
// Memory Usage: 28.8 MB, less than 72.33% of C online submissions for Lowest Common Ancestor of a Binary Search Tree.
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if ((root->val == p->val) || (root->val == q->val)) {
        return root;
    }
    if (p->val > root->val && q->val < root->val) return root;
    if (q->val > root->val && p->val < root->val) return root;
    if (p->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return lowestCommonAncestor(root->left, p, q);
}

// recursion with code optimization
// Runtime: 34 ms, faster than 84.98% of C online submissions for Lowest Common Ancestor of a Binary Search Tree.
//Memory Usage: 29.1 MB, less than 5.53% of C online submissions for Lowest Common Ancestor of a Binary Search Tree.
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (((root->val == p->val) || (root->val == q->val)) || (q->val > root->val && p->val < root->val) || (p->val > root->val && q->val < root->val)){
        return root;
    }
    if (p->val > root->val) return lowestCommonAncestor(root->right, p, q);
    else return lowestCommonAncestor(root->left, p, q);
}