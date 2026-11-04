class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> small, large;
        long long ss=0, ls=0;
        int i=0;
        vector<int> val(nums.begin(), nums.begin()+x);
        sort(val.begin(), val.end());
        for(; i<x/2; i++){
            small.insert(val[i]);
            ss += val[i];
        }
        for(; i<x; i++){
            large.insert(val[i]);
            ls += val[i];
        }
        int mid = (x%2 == 0) ? 0 : val[x/2];

        int m = n-x+1;
        vector<long long> arr(m, 0);
        arr[0] = ls-ss-mid;
        for(i=1; i<m; i++){
            int id = x+i-1;
            // i-1
            if(large.find(nums[i-1]) != large.end()){
                large.erase(large.find(nums[i-1]));
                ls -= nums[i-1];
                if(!large.empty() && nums[id] >= *large.begin()){
                    large.insert(nums[id]);
                    ls += nums[id];
                }
                else{
                    small.insert(nums[id]);
                    ss += nums[id];
                    if(!small.empty()){
                        int val = *prev(small.end());
                        small.erase(prev(small.end()));
                        ss -= val;
                        large.insert(val);
                        ls += val;
                    }
                }
            }
            else{
                small.erase(small.find(nums[i-1]));
                ss -= nums[i-1];
                if(!small.empty() && nums[id] <= *prev(small.end())){
                    small.insert(nums[id]);
                    ss += nums[id];
                }
                else{
                    large.insert(nums[id]);
                    ls += nums[id];
                    if(!large.empty()){
                        int val = *large.begin();
                        large.erase(large.begin());
                        ls -= val;
                        small.insert(val);
                        ss += val;
                    }
                } 
            }
            mid = (x%2 == 0) ? 0 : *large.begin();
            arr[i] = ls-ss-mid;
        }

        vector<vector<long long>> dp(m+1, vector<long long>(k+1, LLONG_MAX));
        for(i=0; i<=m; i++) dp[i][0] = 0;
        for(i=m-1; i>=0; i--){
            for(int j=1; j<=k; j++){
                dp[i][j] = dp[i+1][j]; // not take;
                if(dp[min(m, i+x)][j-1] != LLONG_MAX){
                    dp[i][j] = min(dp[i][j], arr[i]+dp[min(m, i+x)][j-1]);
                }
            }
        }

        return dp[0][k];
    }
};