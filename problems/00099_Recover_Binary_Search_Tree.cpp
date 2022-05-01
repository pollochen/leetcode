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
// 2 inorder traverse
// 1 for current and 1 for recovery
// Runtime: 36 ms, faster than 75.06% of C++ online submissions for Recover Binary Search Tree.
// Memory Usage: 58.1 MB, less than 28.70% of C++ online submissions for Recover Binary Search Tree.
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &out)
    {
        if (root == NULL) return;
        inorder(root->left, out);
        out.push_back(root->val);
        inorder(root->right, out);
    }

    void inorder_recovery(TreeNode *root, vector<int> &nums_sorted, int &idx)
    {
        if (root == NULL) return;
        inorder_recovery(root->left, nums_sorted, idx);
        root->val = nums_sorted[idx++];
        inorder_recovery(root->right, nums_sorted, idx);
    }

    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        sort(nums.begin(), nums.end()); // sort
        int idx = 0;
        inorder_recovery(root, nums, idx);
    }
};