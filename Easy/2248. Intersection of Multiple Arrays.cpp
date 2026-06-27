class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> freq;
        for (auto &arr : nums) {
            for (int x : arr) {
                freq[x]++;
            }
        }
        vector<int> ans;
        int n = nums.size();
        for (auto &p : freq) {
            if (p.second == n) ans.push_back(p.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};