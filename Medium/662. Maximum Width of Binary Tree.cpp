class Solution {
public:
    typedef unsigned long long ull;
    const long long MOD = 1e9 + 7;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, ull>> q;
        q.push({root,1});
        ull res = 1;
        while(!q.empty()){
            int s = q.size();
            ull low = q.front().second;
            ull high;
            while(s--){
                auto p = q.front();
                q.pop();
                p.second -= low;
                high = p.second;
                if(p.first->left) q.push({p.first->left, 2*p.second-1});
                if(p.first->right) q.push({p.first->right, 2*p.second});
            }
            res = max(res, high+1);
        }

        return res;
    }
};