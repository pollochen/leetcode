// https://ithelp.ithome.com.tw/articles/10219199
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
class Solution {
public:
    TreeNode *convert(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;

        int mid = (left + right) / 2;
        TreeNode *n = new TreeNode();
        n->val = nums[mid];
        n->left = convert(nums, left, mid - 1);
        n->right = convert(nums, mid + 1, right);
        return n;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size() - 1);
    }
};

// recursion
// Runtime: 14 ms, faster than 78.22% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage : 21.5 MB, less than 40.91 % of C++ online submissions for Convert Sorted Array to Binary Search Tree.
class Solution {
public:
    TreeNode* bs(vector<int>& nums, int left, int right)
    {
        if (left > right) return NULL;

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = bs(nums, left, mid - 1);
        node->right = bs(nums, mid + 1, right);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bs(nums, 0, nums.size() - 1);
    }
};