class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;

    void solve(TreeNode* root) {
        if (root == NULL) return;
        solve(root->left);

        if (prev != NULL && prev->val > root->val) {
            if (first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        solve(root->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);
        swap(first->val, second->val);
    }
};