class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n);
        int mx = 0;
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
            mx = max(mx, w);
        }
        vector<int> topo;
        queue<int> q;
        vector<int> deg = indegree;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto [v, w] : adj[u]) {
                if (--deg[v] == 0)
                    q.push(v);
            }
        }
        auto check = [&](int limit) -> bool {
            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;
            for (int u : topo) {
                if (dist[u] == INF) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;
                for (auto [v, w] : adj[u]) {
                    if (w < limit) continue;
                    if (v != n - 1 && !online[v]) continue;
                    dist[v] = min(dist[v], dist[u] + (long long)w);
                }
            }
            return dist[n - 1] <= k;
        };
        int l = 0, r = mx;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                res = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return res;
    }
};