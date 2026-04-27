class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dirs = {
            {-1,0}, {0,1}, {1,0}, {0,-1}
        };

        unordered_map<int, vector<int>> nxt = {
            {1, {1,3}},
            {2, {0,2}},
            {3, {3,2}},
            {4, {1,2}},
            {5, {3,0}},
            {6, {1,0}}
        };

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({0,0});

        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();

            if(i==n-1 && j==m-1) return true;
            for(int d:nxt[grid[i][j]]){
                int ni=i+dirs[d][0];
                int nj=j+dirs[d][1];
                
                if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj]){
                    int opp=(d+2)%4;
                    for(int k:nxt[grid[ni][nj]]){
                        if(opp==k){
                            vis[ni][nj]=true;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
        return false;        
    }
};