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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
      
        queue<TreeNode *> que;
        que.push(root);
        
        while (que.empty() == false) {
            int size = que.size();
            int val_prev;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                
                if ((level % 2) == 0) {
                    // even row, all nodes at the level have odd integer values in strictly increasing order (from left to right).
                    if ((node->val & 0x01) == 0) {
                        return false;
                    }
                    if ((i != 0) && ((node->val - val_prev) <= 0)) {
                        return false;
                    }
                } else {
                    // odd row, all nodes at the level have even integer values in strictly decreasing order (from left to right).
                    if ((node->val & 0x01) == 1) {
                        return false;
                    }
                    if ((i != 0) && ((node->val - val_prev) >= 0)) {
                        return false;
                    }
                }

                val_prev = node->val;

                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            
            level++;
                       
        }
        return true;
    }
};