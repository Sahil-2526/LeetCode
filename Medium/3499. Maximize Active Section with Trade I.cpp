class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        int prevZ = 0;
        int newZ = 0;
        int mx = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ones++;
                if(i+1<n && s[i+1] == '0'){
                    prevZ = newZ;
                    newZ = 0;
                }
            }
            else{
                newZ++;
                if(i == n-1 || s[i+1] == '1'){
                    if(prevZ!=0) mx = max(mx, prevZ+newZ);
                }
            }
        }
        return ones+mx;
    }
};