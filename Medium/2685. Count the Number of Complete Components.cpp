class DSU {
private:
    vector<int> parent, sz;
public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> neigh(n, 0);
        DSU dsu(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            neigh[u]++;
            neigh[v]++;
            dsu.unite(u, v);
        }
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            int p = dsu.find(i);
            graph[p].push_back(i);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) continue;
            int s = graph[i].size();
            bool valid = true;
            for (int node : graph[i]) {
                if (neigh[node] != s - 1) {
                    valid = false;
                    break;
                }
            }
            if (valid) count++;
        }
        return count;
    }
};