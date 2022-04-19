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
// BFS with reversed vector index
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage : 12.1 MB, less than 46.23 % of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode *> que;
        que.push(root);
        
        int level = 0;
        
        while ((que.empty() == false)) {
            int size = que.size();
            vector<int> out(size); // pre-allocate vector
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                int idx = i;
                if (level != 0) {
                    idx = size - i - 1; // reverse the index
                }
                out[idx] = node->val;
                if (node->left != NULL)  que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(out);
            level = (level + 1) %2;
        }
        return result;        
    }
};