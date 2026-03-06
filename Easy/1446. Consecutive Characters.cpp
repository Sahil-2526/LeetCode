class Solution {
public:
    int maxPower(string s) {
        int maxm=0;
        int len=s.length();
        int count=0;
        for(int i=0;i<len;i++){
            count++;
            if(i==len-1){
                maxm=max(maxm,count);
            }
            else if(s[i]!=s[i+1]){
                maxm=max(maxm,count);
                count=0;
            }
        }
        return maxm;
    }
};