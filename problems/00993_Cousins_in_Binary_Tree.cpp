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
    bool isCousins(TreeNode* root, int x, int y) {
        bool isX = false;
        bool isY = false;
        
        queue<TreeNode *> q;
        
        q.push(root);
        while (q.empty() == false) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *n = q.front(); q.pop();
                if (n->val == x) isX = true;
                if (n->val == y) isY = true;
                if ((n->left != NULL) && (n->right != NULL)) {
                    // x and y are brothers
                    if ((n->left->val == x) && (n->right->val == y)) return false;
                    if ((n->left->val == y) && (n->right->val == x)) return false;
                }
                
                if (n->left != NULL) q.push(n->left);
                if (n->right != NULL) q.push(n->right);
            }
            
            if (isX && isY) return true;
            if (isX || isY) return false;
        }
        return false;        
    }
};