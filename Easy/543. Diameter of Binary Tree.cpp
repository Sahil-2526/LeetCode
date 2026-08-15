class Solution {
public:
    int mx = 0;
    int solve(TreeNode* node){
        if(node == NULL) return 0;
        int l = solve(node->left);
        int r = solve(node->right);
        mx = max(mx, l+r+1);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return mx-1;
    }
};