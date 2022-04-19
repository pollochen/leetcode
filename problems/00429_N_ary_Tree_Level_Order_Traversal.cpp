/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// BFS + queue
// Runtime: 38 ms, faster than 30.21% of C++ online submissions for N-ary Tree Level Order Traversal.
// Memory Usage: 11.7 MB, less than 64.49% of C++ online submissions for N-ary Tree Level Order Traversal.
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> que;
        vector<vector<int>> result;
        if (root == NULL) return result;

        int size;
        vector<int> out;
        Node *node;
        que.push(root);
        while (que.empty() == false) {
            size = que.size();
            for (int i = 0; i < size; i++) {
                node = que.front();
                que.pop();
                out.push_back(node->val);
                for (int i = 0; i < node->children.size(); i++) {
                    que.push(node->children[i]);
                }
            }
            result.push_back(out);
            out.clear();
        }
        return result;
    }
};