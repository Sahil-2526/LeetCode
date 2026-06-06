class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l = 0;
        int r = 0;
        vector<int> res;
        for(int x : nums) r+=x;
        for(int x : nums){
            r-=x;
            res.push_back(abs(l-r));
            l+=x;
        }
        return res;
    }
};