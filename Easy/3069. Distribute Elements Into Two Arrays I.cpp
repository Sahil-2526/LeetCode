class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> l,r;
        l.push_back(nums[0]);
        r.push_back(nums[1]);
        for(int i=2; i<n; i++){
            if(l.back() > r.back()) l.push_back(nums[i]);
            else r.push_back(nums[i]); 
        }
        for(int i=0; i<r.size(); i++) l.push_back(r[i]);  
        return l;     
    }
};