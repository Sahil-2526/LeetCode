class Solution {
public:
    int minFlips(string s) {
        int zo=0;
        int oz=0;
        int len=s.length();
        vector<vector<int>> a;
        for(int i=0;i<len;i++){
            if(s[i]=='0'){
                if(i%2==0) oz++;
                else zo++;
            }
            else{
                if(i%2==0) zo++;
                else oz++;
            }

            if(i<len-1 && s[i]==s[i+1] && len%2!=0){
                 a.push_back({zo,oz});
            }
        }
        int l=a.size();
        int r=INT_MAX;
        for(int i=0;i<l;i++){
            r=min(r,a[i][0]+oz-a[i][1]);
            r=min(r,a[i][1]+zo-a[i][0]);
        }
        return min({oz,zo,r});
    }
};