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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> stk;

        if (root == NULL) {
            return result;
        }

        TreeNode* node_cur = root;
        // push root
        stk.push(root);
        while (stk.empty() == false) {
            // 1. pick one node
            node_cur = stk.top();
            if ((node_cur->left == NULL) && (node_cur->right == NULL)) {
                stk.pop();
                // 2. publish the value
                result.push_back(node_cur->val);       
            }
       
            // 3. push right node
            if (node_cur->right != NULL) {
                stk.push(node_cur->right);
                node_cur->right = NULL;
            } 

            // 4. push left node
            if (node_cur->left != NULL) {
                stk.push(node_cur->left);
                node_cur->left = NULL;
            } 
        }
        return result;             
    }
};