class Solution {
public:
    int reverseDegree(string s) {
        long long res = 0;
        int i = 1;
        for(char c: s){
            res += (26-(c-'a'))*i*1LL;
            i++;
        }
        return (int)res;
    }
};