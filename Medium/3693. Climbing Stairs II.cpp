class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> stair(n+1, INT_MAX);
        stair[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=3 && i-j>=0; j++){
                stair[i] = min(stair[i], stair[i-j]+costs[i-1]+j*j);
            }
        }
        return (int)stair[n];
    }
};