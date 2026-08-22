class Solution {
public:
    bool checkDivisibility(int n) {
        int val = n, sm = 0, prd = 1;
        while(val!=0){
            sm += val%10;
            prd *= val%10;
            val = val/10;
        }
        return (n%(sm+prd) == 0);
    }
};