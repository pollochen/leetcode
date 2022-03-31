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
// recursion
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 8.5 MB, less than 42.95% of C++ online submissions for Binary Tree Inorder Traversal.
class Solution {
public:
    void in_dfs(TreeNode *root, vector<int> &result)
    {
        if (root == NULL) return;
        if (root->left != NULL) in_dfs(root->left, result);
        result.push_back(root->val);
        if (root->right != NULL) in_dfs(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        in_dfs(root, result);
        return result;
    }
};

// iteration
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 8.5 MB, less than 42.95% of C++ online submissions for Binary Tree Inorder Traversal.
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stk;

        if (root == NULL) {
            return result;
        }

        TreeNode* node_cur = root;
        while (node_cur != NULL || stk.empty() == false) {
            if (node_cur != NULL) {
                // node is available
                // 1. push current node
                stk.push(node_cur);
                // 2. traverse left node
                node_cur = node_cur->left;
            } else {
                // node is not available
                // 1. pop one node
                node_cur = stk.top();
                stk.pop();
                result.push_back(node_cur->val);
                // 2. traverse right node
                node_cur = node_cur->right;
            }
        }
        return result;
    }
};