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
	bool isValidBST(TreeNode *root, long valMin, long valMax) {
		if (root == NULL) return true;
		// node values can't be same value
		if ((root->val <= valMin) || (root->val >= valMax)) {
			return false;
		}
		return isValidBST(root->left, valMin, root->val) && isValidBST(root->right, root->val, valMax);
	}
	bool isValidBST(TreeNode* root) {
		// node value is between [INT_MIN, INT_MAX]
		return isValidBST(root, (long)INT_MIN - 1, (long)INT_MAX + 1);
	}
};
};