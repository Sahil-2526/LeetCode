class Solution {
public:

    bool find(TreeNode* root, int val, TreeNode* original) {
        if (root == NULL) return false;
        if (root->val == val){
            if(root != original) return true;
            else return false;
        }
        if (root->val > val) return find(root->left, val, original);
        return find(root->right, val, original);
    }

    bool trav(TreeNode* root,TreeNode* node, int k) {
        if (node == NULL) return false;
        int target = k - node->val;
        if (find(root, target, node)) return true;

        return trav(root, node->left, k) || trav(root, node->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return trav(root, root, k);
    }
};