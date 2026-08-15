class Solution {
public:
    int mx = INT_MIN;

    int solve(TreeNode* node) {
        if (node == NULL)return 0;
        int l = max(0, solve(node->left));
        int r = max(0, solve(node->right));
        mx = max(mx, l + r + node->val);
        return max(l, r) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return mx;
    }
};