class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S="";
        int n=s.length();
        int z=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='#') z++;
            else{
                if(z>0){
                    z--;
                    continue;
                }
                S=s[i]+S;
            }
        }

        string T="";
        n=t.length();
        z=0;
        for(int i=n-1;i>=0;i--){
            if(t[i]=='#') z++;
            else{
                if(z>0){
                    z--;
                    continue;
                }
                T=t[i]+T;
            }
        }

        if(S==T) return true;
        return false;
    }
};