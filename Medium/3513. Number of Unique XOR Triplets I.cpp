class Solution {
public:
    int msb(int n){
        return bit_floor((unsigned)n);
    }
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n>=3) return msb(n)*2; 
        else return n;
    }
};