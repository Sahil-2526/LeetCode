class Solution {
public:
    vector<vector<int>> res;
    void generate(int i ,vector<int>& nums, vector<int> curr){
        if(i == nums.size()) res.push_back(curr);
        else{ 
            generate(i+1, nums, curr);
            curr.push_back(nums[i]);
            generate(i+1, nums, curr);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        generate(0, nums, {});
        return res;
    }
};