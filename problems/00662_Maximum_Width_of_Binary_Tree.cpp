// https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/1802311/C%2B%2B-oror-BFS-oror-Easy-To-Understand-oror-Full-Explanation
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
    int widthOfBinaryTree(TreeNode* root) {
		// bfs
		queue<pair<TreeNode *, int>> q;
		int result = 0;
		int idx = 0;

		q.push({root, 0});

		while (q.empty() == false) {
			int size = q.size();
			// start is the index of root node for first level
			int start = q.front().second; // first node idx in the queue
			int end   = q.back().second; // last node idx in the queue
			
			// calaulate width
			result = max(result, end - start + 1);

			// push all childs
			for (int i = 0; i < size; i++) {
				pair<TreeNode *, int> p = q.front();
				q.pop();
				int idx = p.second; // node idx
				if (p.first->left)  q.push({ p.first->left,  (long long)2 * idx + 1});
				if (p.first->right) q.push({ p.first->right, (long long)2 * idx + 2});
			}
		}
		return result;
    }
};