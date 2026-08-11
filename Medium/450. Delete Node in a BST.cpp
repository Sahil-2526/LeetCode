class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        TreeNode* parent = NULL;
        TreeNode* curr = root;
        while (curr != NULL && curr->val != key) {
            parent = curr;
            if (key < curr->val) curr = curr->left;
            else curr = curr->right;
        }
        if (curr == NULL) return root;

        if (curr->left == NULL || curr->right == NULL) {
            TreeNode* child;
            if (curr->left != NULL) child = curr->left;
            else child = curr->right;

            if (parent == NULL) return child;

            if (parent->left == curr) parent->left = child;
            else parent->right = child;

            return root;
        }

        TreeNode* p = curr;
        TreeNode* c = curr->right;

        while (c->left != NULL) {
            p = c;
            c = c->left;
        }

        curr->val = c->val;

        if (p->left == c) p->left = c->right;
        else p->right = c->right;

        return root;
    }
};