class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string a, string b){
            return a.length() < b.length();
        });
        unordered_map<string,int> mp;
        int mx = 0;
        for(int i=0; i<n; i++){
            int m = words[i].length();
            if(m == 1){
                mp[words[i]] = 1;
                mx = 1;
                continue;
            }
            int prev_grp = 0;
            for(int j=0; j<m; j++){
                string s = "";
                for(int k=0; k<m; k++){
                    if(j == k) continue;
                    s+=words[i][k];
                }
                if(mp[s]) prev_grp = max(prev_grp, mp[s]);
            }
            mp[words[i]] = prev_grp+1;
            mx = max(mx, prev_grp+1);
        }
        return mx;
    }
};