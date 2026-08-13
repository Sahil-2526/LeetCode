struct Node{
    bool isBST;
    int mn;
    int mx;
    int sum;
};
class Solution {
public:
    int ans = 0;
    Node solve(TreeNode* root) {
        if (root == NULL)
            return {true, INT_MAX, INT_MIN, 0};

        Node l = solve(root->left);
        Node r = solve(root->right);

        if (l.isBST && r.isBST && l.mx < root->val && root->val < r.mn) {
            int currSum = l.sum + r.sum + root->val;
            ans = max(ans, currSum);
            return { true, min(l.mn, root->val), max(r.mx, root->val), currSum };
        }
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};