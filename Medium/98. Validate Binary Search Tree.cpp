class Solution {
public:
    typedef long long ll;

    bool solve(TreeNode* root, ll l, ll h) {
        if (root == nullptr)
            return true;

        ll child_val = 1LL*root->val;

        if (child_val <= l || child_val >= h) return false;

        return solve(root->left, l, child_val) &&
               solve(root->right, child_val, h);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};