class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<bool> sus(n, false);
        queue<int> q;
        q.push(k);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (sus[node]) continue;
            sus[node] = true;

            for (int x : adj[node]) {
                if (!sus[x])
                    q.push(x);
            }
        }

        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!sus[u] && sus[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!sus[i])
                ans.push_back(i);
        }

        return ans;
    }
};