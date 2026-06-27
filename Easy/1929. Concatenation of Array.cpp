class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        for(int x:nums) res.push_back(x);
        for(int x:nums) res.push_back(x);
        return res;
    }
};