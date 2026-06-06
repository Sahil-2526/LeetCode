class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int l = 0;
        int r = 0;
        for(int x : nums) r+=x;
        int i=0;
        for(int x : nums){
            r-=x;
            if( l == r ) return i;
            l+=x;
            i++;
        }
        return -1;
    }
};