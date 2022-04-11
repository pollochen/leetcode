// recursion
// Runtime: 48 ms, faster than 25.00% of C online submissions for Linked List in Binary Tree.
// Memory Usage: 14.2 MB, less than 38.64% of C online submissions for Linked List in Binary Tree.
bool check_dfs(struct ListNode* head, struct TreeNode* root) {
    if (head == NULL) {
        // found
        return true;
    }
    if (root == NULL) {
        // reach end of tree, and head is not NULL
        return false;
    }
    if (root->val != head->val) {
        // no match
        return false;
    }
    return check_dfs(head->next, root->left) || check_dfs(head->next, root->right);
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if (head == NULL || root == NULL) {
        return false;
    }

    // need to check current and children
    return check_dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
}

// FAIL version
bool isSubPath(struct ListNode* head, struct TreeNode* root){
    if (head == NULL || root == NULL) {
        return false;
    }
    if (head->val == root->val) {
        // this just check head and root
        // if it fails, no more check from children
        return check_dfs(head, root);
    } else {
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
}