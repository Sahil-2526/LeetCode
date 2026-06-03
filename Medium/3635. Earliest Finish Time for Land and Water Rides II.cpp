class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        long long landmin = LLONG_MAX;
        long long watermin = LLONG_MAX;
        long long ans = LLONG_MAX;
        for(int i = 0; i < n; i++){
            landmin = min( landmin, 1LL*landStartTime[i] + landDuration[i]);
        }
        for(int i = 0; i < m; i++){
            long long finish = max(landmin, 1LL*waterStartTime[i]) + waterDuration[i];
            ans = min( ans, finish);
            watermin = min( watermin, 1LL*waterStartTime[i] + waterDuration[i]);
        }
        for(int i = 0; i < n; i++){
            long long finish = max(watermin, 1LL*landStartTime[i]) + landDuration[i];
            ans = min( ans, finish);
        }
        return (int)ans;
    }
};