class Solution {
public:
    int bitwiseComplement(int n) {
        long long mx=LONG_MAX;
        int val = 0;
        if(n==0) return 1;
        int i=0;
        while(n%mx>val%mx){
            val=(val+(int)pow(2,i))%mx;
            i++;
        }
        return (val-n)%mx;
        
    }
};