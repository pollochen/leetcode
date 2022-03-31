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
// interation stack version
// Runtime: 7 ms, faster than 50.39% of C++ online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 12.4 MB, less than 85.07% of C++ online submissions for Binary Tree Level Order Traversal.
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> out;
        queue<TreeNode *> que;
        TreeNode *node;
        int size;

        if (root == NULL) return result;

        que.push(root);

        while (que.empty() == false) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                node = que.front(); que.pop();
                out.push_back(node->val);
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(out);
            out.clear();
        }
        return result;
    }
};