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
// inorder traverse to get a sorted list and 2 pointers solution
// Runtime: 43 ms, faster than 79.69% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 36.6 MB, less than 89.32% of C++ online submissions for Two Sum IV - Input is a BST.
class Solution {
public:
    void inorder(TreeNode *root, vector<int> &nums) {
        if (root == NULL) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int left = 0;
        int right = nums.size() - 1;
        int sum;
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum == k) return true;
            if (sum > k) right--;
            else left++;
        }
        return false;
    }
};