class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int i, int j, int k) {
        if (j > k) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int pos = j;
        while (inorder[pos] != preorder[i])
            pos++;
        int leftSize = pos - j;
        root->left = solve(preorder, inorder, i + 1, j, pos - 1);
        root->right = solve(preorder, inorder, i + leftSize + 1, pos + 1, k);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, 0, inorder.size()-1);
    }
};