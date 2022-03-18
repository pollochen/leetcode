// https://www.cnblogs.com/grandyang/p/4620012.html
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int kthSmallest_dfs(struct TreeNode* root, int *k)
{
	if (root == NULL) return 0;
	int val = kthSmallest_dfs(root->left, k);
	if (*k == 0) {
		return val;
	}
	// center node
	*k = *k - 1;
	if (*k == 0) {
		return root->val;
	}

	// right
	return kthSmallest_dfs(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k) {
	int x = k;
	return kthSmallest_dfs(root, &k);
}