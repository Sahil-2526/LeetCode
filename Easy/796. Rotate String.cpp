class Solution {
public:
    vector<int> computeLPS(string p){
        int m=p.length();
        vector<int> lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(p[i]==p[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0) len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    bool KMPSearch(string t,string p){
        int n=t.length();
        int m=p.length();
        vector<int> lps=computeLPS(p);
        int i=0;
        int j=0;
        while(i<n){
            if(t[i]==p[j]){
                i++;
                j++;
            }
            if(j==m){
                j=lps[j-1];
                return true;
            }
            else if(i<n && t[i]!=p[j]){
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string newstr=s+s;
        return KMPSearch(s+s,goal);
    }
};

// can use rotate function directly 