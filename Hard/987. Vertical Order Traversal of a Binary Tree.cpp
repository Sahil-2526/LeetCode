class Solution {
public:
    int lmH = 0;
    int rmH = 0;
    vector<vector<int>> res;

    void findIdx(TreeNode* node, int val){
        if(node->left) findIdx(node->left, val-1);
        if(node->right) findIdx(node->right, val+1);
        lmH = min(lmH, val);
        rmH = max(rmH, val);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        findIdx(root, 0);

        vector<vector<int>> res(rmH-lmH+1);

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            int s = q.size();
            vector<pair<int, int>> semi_res;
            while(s--){
                pair<TreeNode*,int> node = q.front();
                q.pop();
                if(node.first->left) q.push({node.first->left, node.second-1});
                if(node.first->right) q.push({node.first->right, node.second+1});
                semi_res.push_back({node.first->val, node.second});
            }
            sort(semi_res.begin(), semi_res.end(), [](auto a, auto b){
                return a.first+a.second < b.first+b.second;
            });
            for(int i=0; i<semi_res.size(); i++){
                res[semi_res[i].second-lmH].push_back(semi_res[i].first);
            }
        }

        return res;
    }
};