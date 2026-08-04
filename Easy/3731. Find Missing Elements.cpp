class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = nums[0];
        int mx = nums[0];
        set<int> s;
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
            s.insert(x);
        }
        vector<int> res;
        for (int i = mn; i <= mx; i++) {
            if (s.find(i) == s.end())
                res.push_back(i);
        }
        return res;
    }
};