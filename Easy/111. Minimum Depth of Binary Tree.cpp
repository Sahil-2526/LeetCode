/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth = INT_MAX;
    void dfs(TreeNode* r,int d) {
        if(r == nullptr) return;
        if (r->left == nullptr && r->right == nullptr) depth = min(depth,d);
        dfs(r->left, d+1);
        dfs(r->right, d+1);
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root, 1);
        return depth;
    }
};