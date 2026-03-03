class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> n = nums;
        vector<int> vec(2);
        sort(nums.begin(), nums.end());
        int left_idx = 0;
        int right_idx = nums.size()-1;
        while(left_idx < right_idx){
            if(nums[left_idx] + nums[right_idx] > target) right_idx--;
            if(nums[left_idx] + nums[right_idx] < target) left_idx++;
            if(nums[left_idx] + nums[right_idx] == target) break;
        }
        for(int i=0;i<n.size();i++){
                    if(n[i] == nums[left_idx]){
                        left_idx = i;
                        break; } }
        for(int i=0;i<n.size();i++){
                    if(n[i] == nums[right_idx] && left_idx != i){
                        right_idx = i;
                        break;} }
        vec[0] = left_idx;
        vec[1] = right_idx;
        return vec;
    }
};