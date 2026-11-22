class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int a=-1,b=n;
        for(int i=0; i<n; i++){
            if(s[i] == 'a') a = i;
            if(s[n-i-1] == 'b') b = n-i-1;
        }
        if(a<b) return true;
        return false;
    }
};