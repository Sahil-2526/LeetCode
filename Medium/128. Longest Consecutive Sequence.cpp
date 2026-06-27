class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int num : nums) {
            if (mp[num] != 0) continue; 
            int l = mp[num-1];
            int r = mp[num+1];
            int len = l + r + 1;
            mp[num] = len;
            mp[num - l] = len;
            mp[num + r] = len;
            ans = max(ans, len);
        }

        return ans;
    }
};