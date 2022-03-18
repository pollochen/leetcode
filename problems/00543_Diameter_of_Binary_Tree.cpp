// https://www.cnblogs.com/grandyang/p/6607318.html
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
	int max_diameter(TreeNode* root, int& result) {
		if (root == NULL) return 0;
		int left = max_diameter(root->left, result);
		int right = max_diameter(root->right, result);
		result = max(left + right, result);
		return max(left, right) + 1;
	}
	int diameterOfBinaryTree(TreeNode* root) {
		int result = 0;
		max_diameter(root, result);
		return result;
	}
};