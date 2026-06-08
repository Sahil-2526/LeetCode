class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        int count = 0;
        for(int x: nums) {
            if(x < pivot) res.push_back(x);
            if( x == pivot ) count++;
        }
        while(count>0){
            res.push_back(pivot);
            count--;
        }
        for(int x: nums) {
            if(x > pivot) res.push_back(x);
        }
        return res;
    }
};