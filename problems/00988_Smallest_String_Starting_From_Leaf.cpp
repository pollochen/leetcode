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
	string result_s;
	string smallestFromLeaf(TreeNode* root) {
		result_s = "~";
		dfs_smallestFromLeaf(root, "");
        return result_s;
	}

	void dfs_smallestFromLeaf(TreeNode *node, string s) {
		if (node == NULL) return;
		char x = 'a' + node->val;
		s = string(1, x) + s;
		if (node->left == NULL && node->right == NULL) {
			result_s = std::min(s, result_s);
		}
		dfs_smallestFromLeaf(node->left, s);
		dfs_smallestFromLeaf(node->right, s);
	}
};