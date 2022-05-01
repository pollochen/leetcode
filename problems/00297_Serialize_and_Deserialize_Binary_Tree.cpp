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

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/1959733/Python-clean-solution-using-BFS
// BFS (queue)
// Runtime: 353 ms, faster than 11.44% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 700.6 MB, less than 5.44% of C++ online submissions for Serialize and Deserialize Binary Tree.
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode *> que;

        if (root == NULL) return result;

        result += to_string(root->val) + ",";

        int size;
        que.push(root);
        while (que.empty() == false) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                if (node->left != NULL) {
                    result += to_string(node->left->val) + ",";
                    que.push(node->left);
                } else {
                    result += "X,";
                }
                if (node->right != NULL) {
                    result += to_string(node->right->val) + ",";
                    que.push(node->right);
                } else {
                    result += "X,";
                }
            }
        }
        //printf("%s", result.c_str());
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

        if (data.length() == 0) return NULL;

        TreeNode *root = get_next(data, pos);

        queue<TreeNode *> que;
        que.push(root);
        int size;
        while (pos < data.length()) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front(); que.pop();
                TreeNode *node_l = get_next(data, pos);
                TreeNode *node_r = get_next(data, pos);
                node->left  = node_l;
                node->right = node_r;
                if (node_l != NULL) que.push(node_l);
                if (node_r != NULL) que.push(node_r);
            }
        }
        return root;
    }
};

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/1960502/C%2B%2B-oror-100-oror-Easy-with-Explanation-oror-Queue-oror-Recursion
// pre-order traverse + queue
// Runtime: 97 ms, faster than 25.60% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 34.5 MB, less than 41.62% of C++ online submissions for Serialize and Deserialize Binary Tree.
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "X,";
        // pre-order traverse (center -> left -> right)
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    void parse(string &data, queue<TreeNode *> &que)
    {
        int len = data.length();
        int pos = 0;
        char ch;
        string val;
        while (pos < len) {
            ch = data[pos];
            if (ch == 'X') {
                que.push(NULL);
                pos += 2;
            } else if (ch == ',') {
                TreeNode *node = new TreeNode(stoi(val));
                que.push(node);
                val = "";
                pos++;
            } else {
                pos++;
                val += ch;
            }
        }
        if (val.length() > 0) {
            TreeNode *node = new TreeNode(stoi(val));
            que.push(node);
        }
    }

    // pre-order traverse
    void x(TreeNode *root, queue<TreeNode *> &que)
    {
        if (root == NULL) return;
        root->left = que.front(); que.pop();
        x(root->left, que);
        root->right = que.front(); que.pop();
        x(root->right, que);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode *> que;
        parse(data, que);
        TreeNode *root = que.front(); que.pop();
        x(root, que);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));