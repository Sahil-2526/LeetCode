class Solution {
public:
    int maxProduct(int n) {
        int l = 0;
        int sl = 0;
        while(n > 0){
            int val = n%10;
            n = n/10;
            if(val >= l){
                sl = l;
                l = val;
            }
            else if(val > sl) sl = val; 
        }
        return l*sl;
    }
};