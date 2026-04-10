#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            int step = query[2];
            long long multiplier = query[3];
            if (multiplier == 1) continue;
            for (int j = start; j <= end; j += step) {
                nums[j] = (1LL * nums[j] * multiplier) % MOD;
            }
        }

        int result = 0;
        for (int val : nums) {
            result ^= val;
        }

        return result;
    }
};