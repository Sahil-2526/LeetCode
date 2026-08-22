class Solution {
public:
    TreeNode* make(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return root;

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = NULL;

        if (left != NULL) {
            root->right = left;
            TreeNode* tail = make(left);
            if (right != NULL) {
                tail->right = right;
                tail = make(right);
            }
            return tail;
        }

        root->right = right;
        return make(right);
    }

    void flatten(TreeNode* root) {
        make(root);
    }
};