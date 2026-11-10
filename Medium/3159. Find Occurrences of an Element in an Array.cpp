class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == x) pos.push_back(i);
        }
        int n = pos.size();
        int m = queries.size();
        vector<int> res(m);
        for(int i=0; i<m; i++){
            if(queries[i] > n) res[i] = -1;
            else res[i] = pos[queries[i]-1];
        }
        return res;
    }
};