class Solution {
public:
    int findComplement(int num) {
        long long mx=LONG_MAX;
        int val = 0;
        if(num==0) return 1;
        int i=0;
        while(num%mx>val%mx){
            val=(val+(int)pow(2,i))%mx;
            i++;
        }
        return (val-num)%mx;
    }
};