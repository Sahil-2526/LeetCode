class Solution { 
public: 
    int atMost(int k, vector<int>& nums) {
        unordered_map<int, int> mp;
        int i = 0;
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            count += j-i+1;
        }
        return count;
    };
    int subarraysWithKDistinct(vector<int>& nums, int k) { 
        return atMost(k, nums) - atMost(k-1, nums);
    } 
};