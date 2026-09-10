class Solution {
public:
    typedef pair<int, int> pii;
    int ans = 0;
    pii solve(TreeNode* node){
        int val = node->val;
        int nc = 1;
        if(node->left != NULL){
            pii l = solve(node->left);
            val += l.first;
            nc += l.second;
        }
        if(node->right != NULL){
            pii r = solve(node->right);
            val += r.first;
            nc += r.second;
        }
        if(val/nc == node->val) ans++;
        return {val, nc};
    }
    int averageOfSubtree(TreeNode* root) {
        pii a = solve(root);
        return ans;
    }
};