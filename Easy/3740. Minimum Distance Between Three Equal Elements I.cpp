#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> pos(101);
        
        for(int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= 100; i++){
            if(pos[i].size() < 3) continue;
            for(int j = 0; j + 2 < pos[i].size(); j++){
                int dist = 2 * (pos[i][j+2] - pos[i][j]);
                ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};