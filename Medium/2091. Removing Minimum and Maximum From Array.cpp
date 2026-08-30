class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int max_idx = max_element(nums.begin(), nums.end())-nums.begin();
        int min_idx = min_element(nums.begin(), nums.end())-nums.begin();
        int c1 = (n-max(min_idx,max_idx)) + (min(min_idx,max_idx)+1);
        int c2 = (max(min_idx,max_idx)+1);
        int c3 = (n-min(min_idx,max_idx));
        return min({c1,c2,c3});
    }
};