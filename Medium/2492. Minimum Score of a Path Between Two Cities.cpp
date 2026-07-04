class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(size[a] < size[b]){
            int t = a;
            a = b;
            b = t;
        }
        parent[b] = a;
        size[a] += size[b];
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        auto tree = DSU(n);
        for(auto& road : roads){
            tree.unite(road[0],road[1]);
        }
        int origParent = tree.find(1);
        int mn = INT_MAX;
        for(auto& road: roads){
            if(tree.find(road[0]) == origParent) mn = min(mn, road[2]);
        }
        return mn;
    }
};