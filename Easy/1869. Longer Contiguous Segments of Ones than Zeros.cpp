class Solution {
public:
    bool checkZeroOnes(string s) {
        int len=s.length();
        int ones=0;
        int zeros=0;
        int count=0;
        for(int i=0;i<len;i++){
            count++;
            if(i==len-1){
                if(s[i]=='1') ones=max(ones,count);
                else zeros=max(zeros,count);
            }
            else if(s[i]=='0' && s[i+1]=='1'){
                zeros=max(zeros,count);
                count=0;
            }
            else if(s[i]=='1' && s[i+1]=='0'){
                ones=max(ones,count);
                count=0;
            }
        }
        return ones>zeros;
    }
};

