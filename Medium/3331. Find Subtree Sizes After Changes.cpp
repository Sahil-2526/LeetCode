
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), tree(n);
        vector<int> np(n, -1), ans(n, 1);
    
        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u){
            int c = s[u] - 'a';
            int prev = last[c];

            if(prev != -1) np[u] = prev;
            else np[u] = parent[u];

            last[c] = u;

            for(int v : adj[u]){
                dfs(v);
            }

            last[c] = prev;
        };

        dfs(0);

        for(int i = 1; i < n; i++){
            tree[np[i]].push_back(i);
        }

        function<int(int)> dfs2 = [&](int u){
            for(int v : tree[u]){
                ans[u] += dfs2(v);
            }
            return ans[u];
        };

        dfs2(0);

        return ans;
    }
};
