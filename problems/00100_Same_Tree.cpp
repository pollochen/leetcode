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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode *> qp;
        queue<TreeNode *> qq;

        if (p == NULL && q == NULL) return true;
        if (p == NULL && q != NULL) return false;
        if (p != NULL && q == NULL) return false;

        qp.push(p);
        qq.push(q);

        while (qp.empty() == false || qq.empty() == false) {
            if (qp.size() != qq.size()) {
                return false;
            }

            int size = qp.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node_p = qp.front(); qp.pop();
                TreeNode *node_q = qq.front(); qq.pop();

                if (node_p->val != node_q->val) {
                    return false;
                }

                bool isLeftNull1 = false;
                bool isRightNull1 = false;
                bool isLeftNull2 = false;
                bool isRightNull2 = false;
                if (node_p->left != NULL) {
                    isLeftNull1 = true;
                    qp.push(node_p->left);
                }

                if (node_p->right != NULL) {
                    isRightNull1 = true;
                   qp.push(node_p->right);
                }


                if (node_q->left != NULL) {
                   isLeftNull2 = true;
                   qq.push(node_q->left);
                }
                if (node_q->right != NULL) {
                    isRightNull2 = true;
                    qq.push(node_q->right);
                }

                if (isLeftNull1 ^ isLeftNull2) return false;
                if (isRightNull1 ^ isRightNull2) return false;
            }
        }
        return true;
    }
};