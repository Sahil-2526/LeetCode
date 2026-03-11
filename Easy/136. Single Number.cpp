#include<set>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size();
        set<int> s;
        for(int i=0;i<len;i++){
            int val=nums[i];
            if(s.find(val)==s.end()) s.insert(val);
            else s.erase(val);
        }
        return *s.begin();
    }
};