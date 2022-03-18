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
	int sumNumbers(TreeNode* root) {
		int result = 0;
		if (root == NULL) return 0;
		dfs_sum(root, 0, &result);
		return result;
	}
	void dfs_sum(TreeNode *node, int sum, int *total)
	{
		if (node == NULL) return ;
		sum = sum * 10 + node->val;
		if ((node->left == NULL) && (node->right == NULL)) {
			*total += sum;
		}
		if (node->left != NULL) dfs_sum(node->left, sum, total);
		if (node->right != NULL) dfs_sum(node->right, sum, total);
	}    
};