class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long min = (*min_element(nums.begin(), nums.end()));
        long long res = 0;
        for(int i=0; i<n; i++) res += abs(nums[i]-min);
        return (int)res;
    }
};