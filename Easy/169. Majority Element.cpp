class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for(int x: nums){
            if(count == 0){
                candidate = x;
                count = 1;
            }
            else if(candidate == x) count++;
            else count--;
        }
        return candidate;
    }
};