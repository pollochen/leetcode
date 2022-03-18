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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        while (q.empty() == false) {
            vector<int> out;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // publish value in queue
                TreeNode *n = q.front(); q.pop();
                out.push_back(n->val);

                // push all child nodes into queue
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            result.push_back(out);
        }
        return result;        
    }
};