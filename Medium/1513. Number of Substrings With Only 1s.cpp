class Solution {
public:
    int numSub(string s) {
        long long maxm=0;
        int len=s.length();
        long long count=0;
        long long MAX=1e9+7;
        for(int i=0;i<len;i++){
            if(s[i]=='1') count++;
            if(i==len-1){
                maxm=(maxm+(count*(count+1)/2)%MAX)%MAX;
            }
            else if(s[i]=='1' && s[i+1]=='0'){
                maxm=(maxm+(count*(count+1)/2)%MAX)%MAX;
                count=0;
            }
        }
        return maxm;
    }
};