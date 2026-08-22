class Solution {
public:
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int i, int j, int k) {
        if (j > k) return NULL;
        TreeNode* root = new TreeNode(postorder[i]);
        int pos = j;
        while (inorder[pos] != postorder[i])
            pos++;
        int rsize = k-pos;
        root->right = solve(postorder, inorder, i-1, pos+1, k);
        root->left = solve(postorder, inorder, i-rsize-1, j, pos-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(postorder, inorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
};