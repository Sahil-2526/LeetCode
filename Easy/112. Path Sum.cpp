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
    bool dfs(TreeNode* r,int d) {
        if(r == nullptr) return false;
        d-=r->val;
        if (r->left == nullptr && r->right == nullptr && d == 0) return true;
        return dfs(r->left, d) || dfs(r->right, d);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};