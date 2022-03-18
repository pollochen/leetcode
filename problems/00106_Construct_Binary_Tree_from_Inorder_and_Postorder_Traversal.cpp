// https://www.cnblogs.com/grandyang/p/4296500.html
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
	TreeNode* buildTree(vector<int>& inorder, int iLeft, int iRight, vector<int>& postorder, int pLeft, int pRight) {
		if ((pLeft > pRight) || (iLeft > iRight)) return NULL;
		
		int val_root = postorder[pRight];
		int pos_root = -1;

		// find pos of root value in inorder array
		for (int i = iLeft; i <= iRight; i++) {
			if (inorder[i] == val_root) {
				pos_root = i;
				break;
			}
		}
		
		int l_len = pos_root - iLeft;
		int r_len = iRight - pos_root;
		TreeNode* root = new TreeNode(val_root);
		root->left  = buildTree(inorder, iLeft       , pos_root - 1, postorder, pLeft, pLeft + l_len - 1);
		root->right = buildTree(inorder, pos_root + 1, iRight      , postorder, pLeft + l_len, pRight - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
};