class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == n) return *max_element(nums.begin(), nums.end()); 
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        int res = -1;
        if (k == 1){
            int mx = -1;
            for (int x : nums){
                if(mp[x] == 1) mx = max(mx, x);
            }
            return mx;
        }
        if (mp[nums[0]] == 1) res = max(res, nums[0]);
        if (mp[nums[n-1]] == 1) res = max(res, nums[n-1]);
        return res;
    }
};