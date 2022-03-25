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
 
// Breath-first search and pick right mode element in the same level/depth
// Runtime: 3 ms, faster than 79.85% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 12.2 MB, less than 20.78% of C++ online submissions for Binary Tree Right Side View.
 class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> que;
        int size;
        TreeNode* node;

        if (root == NULL) return result;
        
        // BFS
        que.push(root);
        while (que.empty() == false) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                node = que.front(); que.pop();
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
                if (i == size - 1) {
                    // last element in this level, publish it
                    result.push_back(node->val);
                }
            }
        }

        return result;
    }
};