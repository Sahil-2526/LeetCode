class Solution {
public:
    bool checkOnesSegment(string s) {
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='0' && s[i+1]=='1') return false;
        }
        return true;
    }
};