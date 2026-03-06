class Solution {
public:
    int minimumChairs(string s) {
        int len=s.length();
        int count=0;
        int maxm=0;
        for(int i=0;i<len;i++){
            if(s[i]=='E'){
                count++;
                maxm=max(maxm,count); }
            else count--;
        }
        return maxm;
    }
};