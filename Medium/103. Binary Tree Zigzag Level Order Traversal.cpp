class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> res;
        if(root == NULL) return res;
        bool rev = false;
        while(!q.empty()){
            int n = q.size();
            vector<int> semi_res;
            while(n--){
                TreeNode* node = q.front();
                q.pop();
                semi_res.push_back(node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(rev){
                reverse(semi_res.begin(), semi_res.end());
                rev = false;
            }
            else rev = true;
            res.push_back(semi_res);
        }
        return res;
    }
};