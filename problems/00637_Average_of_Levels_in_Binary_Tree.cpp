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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;        
        queue<TreeNode *> q;
        
        if (root == NULL) return result;

        q.push(root);
        while (q.empty() == false) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *n = q.front(); q.pop();
                
                sum += n->val;

                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            result.push_back(sum/size);
        }
        return result;               
    }
};