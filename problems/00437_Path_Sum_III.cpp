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
	int result = 0;

	int pathSum(TreeNode* root, int targetSum) {
		result = 0;
		if (root == NULL) {
			return result;
		}

		queue<TreeNode *> que;
		que.push(root);

		// traverse all nodes
		while (que.empty() == false) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode *node = que.front(); que.pop();
				// find possible path
				dfs_pathsum(node, targetSum);

				if (node->left != NULL) que.push(node->left);
				if (node->right != NULL) que.push(node->right);
			}
		}
		return result;
	}
	void dfs_pathsum(TreeNode *node, int sum)
	{
		if (node == NULL) return;
		if (node->val == sum) {
			result++;
		}

  		if (node->left != NULL) dfs_pathsum(node->left, sum - node->val);
    	if (node->right != NULL) dfs_pathsum(node->right, sum - node->val);            
	}
};
