#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        unordered_map<int,int> rob_dist;
        for(int i = 0; i < n; i++) rob_dist[robots[i]] = distance[i];

        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());
  
        auto countWalls = [&](int l, int r)->int {
            return upper_bound(walls.begin(), walls.end(), r)
                 - lower_bound(walls.begin(), walls.end(), l);
        };

        vector<vector<int>> dp(n, vector<int>(2, 0));

        for(int i = 0; i < n; i++){
            int l, r;
            if(i > 0) l = max(robots[i] - rob_dist[robots[i]], robots[i-1] + 1);
            else l = robots[i] - rob_dist[robots[i]];

            if(i < n - 1) r = min(robots[i] + rob_dist[robots[i]], robots[i+1] - 1);
            else r = robots[i] + rob_dist[robots[i]];

            int left = countWalls(l, robots[i]);
            int right = countWalls(robots[i], r);

            if(i == 0){
                dp[i][0] = left;
                dp[i][1] = right;
                continue;
            }

            int overlap = countWalls(robots[i-1], robots[i]);

            dp[i][0] = max( dp[i-1][0] + left,
                dp[i-1][1]-
                (countWalls(robots[i-1], robots[i-1] + rob_dist[robots[i-1]]))+
                min (left +
                countWalls(robots[i-1],robots[i-1] + rob_dist[robots[i-1]]),
                 overlap));
            dp[i][1] = max(dp[i-1][0]+right,dp[i-1][1] + right);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};