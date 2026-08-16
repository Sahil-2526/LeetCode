class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> res;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(s == 0) res.push_back(node->val);
            }
        }

        return res;
    }
};