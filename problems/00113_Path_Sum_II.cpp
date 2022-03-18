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
    vector<vector<int>> result;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        vector<int> out;
        dfs(root, targetSum, out);
        return result;
    }
private:
    void dfs(TreeNode *node, int targetSum, vector<int> &out) {
        if (node == NULL) return;
        out.push_back(node->val);
        if ((node->val == targetSum) && (node->left == NULL) && (node->right == NULL)) {
            result.push_back(out);
            out.pop_back();
            return;
        }
        dfs(node->left, targetSum - node->val, out);
        dfs(node->right, targetSum - node->val, out);
        out.pop_back();
    }
};