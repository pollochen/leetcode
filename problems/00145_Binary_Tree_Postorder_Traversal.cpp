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
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 8.6 MB, less than 38.93% of C++ online submissions for Binary Tree Postorder Traversal.
class Solution {
public:
    void post_dfs(TreeNode *root, vector<int> &result)
    {
        if (root == NULL) return;
        if (root->left != NULL) post_dfs(root->left, result);
        if (root->right != NULL) post_dfs(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        post_dfs(root, result);
        return result;
    }
};

// https://www.geeksforgeeks.org/iterative-postorder-traversal/?ref=lbp
// iteration 2-stack version
// Runtime: 8 ms, faster than 7.80% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 8.5 MB, less than 38.93% of C++ online submissions for Binary Tree Postorder Traversal.
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stk1, stk2;
        TreeNode* node;

        if (root == NULL) return result;

        stk1.push(root);

        while (stk1.empty() == false) {

            node = stk1.top(); stk1.pop();

            stk2.push(node);
            if (node->left != NULL) stk1.push(node->left);
            if (node->right != NULL) stk1.push(node->right);
        }
        while (stk2.empty() == false) {
            result.push_back(stk2.top()->val);
            stk2.pop();
        }
        return result;
    }
};