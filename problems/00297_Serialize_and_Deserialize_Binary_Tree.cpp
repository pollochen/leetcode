/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// brute force (BFS)
// TLE version
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode *> que;
        que.push(root);
        int size;
        bool flag_end = false;
        while (flag_end == false) {
            size = que.size();
            flag_end = true;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                if (node == NULL) {
                    result += "X,";
                    que.push(NULL);
                    que.push(NULL);
                } else {
                    result += to_string(node->val) + ",";
                    if (node->left || node->right) flag_end = false;
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }
        printf("%s", result.c_str());
        return result;
    }

    TreeNode *get_next(string s, int &pos)
    {
        int len = s.length();
        int val = 0;
        int flag_minus = 1;
        char ch;
        while (pos < len) {
            ch = s[pos];

            if (ch == 'X') {
                pos += 2;
                return NULL;
            } else if (ch == '-') {
                flag_minus = -1;
                pos++;
            } else if (ch <= '9' && ch >= '0') {
                val = val * 10 + ch - '0';
                pos++;
            } else {
                pos++;
                return new TreeNode(val * flag_minus);
            }
        }
        return new TreeNode(val * flag_minus);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        TreeNode *root = get_next(data, pos);
        if (root == NULL) return root;

        //return NULL;

        queue<TreeNode *> que;
        que.push(root);
        int size;
        while (pos < data.length()) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                TreeNode *node_l = get_next(data, pos);
                TreeNode *node_r = get_next(data, pos);
                if (node != NULL) {
                    node->left  = node_l;
                    node->right = node_r;
                }
                que.push(node_l);
                que.push(node_r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));