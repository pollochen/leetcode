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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if ((root->left == NULL) && (root->right == NULL)) {
            result.push_back(to_string(root->val));
            return result;
        }
        dfs(root, "", result);
        return result;
    }
    
private:
    void dfs(TreeNode *node, string out, vector<string> &result)
    {
        if (node == NULL) return;
        string s = std::to_string(node->val);
        if ((node->left == NULL) && (node->right == NULL)) {
            // leaf node
            out = out + "->" + s;
            result.push_back(out);
        }
        if (out.empty() == false) out = out + "->" + s;
        else out = s;
        if (node->left != NULL) dfs(node->left, out, result);
        if (node->right != NULL) dfs(node->right, out, result);
    }
};