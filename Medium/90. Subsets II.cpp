class Solution {
public:
    vector<vector<int>> res;

    void generate(int i, vector<int>& nums, vector<int> curr) {
        res.push_back(curr);

        for (int j = i; j < nums.size(); j++) {
            if (j>i && nums[j] == nums[j-1]) continue;
            curr.push_back(nums[j]);
            generate(j+1, nums, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        generate(0, nums, {});
        return res;
    }
};