#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        int m = requests.size();
        long long mod = 1e9 + 7;
        
        vector<int> count(n, 0);
        for(int i = 0; i < m; i++){
            count[requests[i][0]]++;
            if(requests[i][1] + 1 < n) count[requests[i][1] + 1]--;
        }
        
        for(int i = 1; i < n; i++){
            count[i] = count[i - 1] + count[i];
        }        
        
        sort(count.begin(), count.end());
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = 0; i < n; i++){
            res = (res + (long long)count[i] * nums[i]) % mod;
        }

        return (int)res;
    }
};