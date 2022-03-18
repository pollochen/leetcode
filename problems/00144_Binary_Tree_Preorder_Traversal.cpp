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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stk;

        if (root == NULL) {
            return result;
        }

        TreeNode* node_cur = root;
        // push root
        stk.push(root);
        while (stk.empty() == false) {
            // 1. pop one node
            node_cur = stk.top();
            stk.pop();

            // 2. publish the value
            result.push_back(node_cur->val);
                
            // 3. push right node
            if (node_cur->right != NULL) stk.push(node_cur->right);

            // 4. push left node
            if (node_cur->left != NULL) stk.push(node_cur->left);
        }
        return result;        
    }
};