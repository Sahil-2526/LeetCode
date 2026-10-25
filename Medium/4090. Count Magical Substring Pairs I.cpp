class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        vector<vector<int>> uniq(n, vector<int>(27, 0));
        for(int i=0; i<n; i++){
            set<char> st;
            for(int j=i; j<n; j++){
                st.insert(s[j]);
                int u = st.size();
                uniq[i][u]++;
            }
        }

        int res = 0;
        for(int i=0; i<n-1; i++){
            set<char> st;
            for(int j=i; j<n-1; j++){
                st.insert(s[j]);
                int u = st.size();
                res += uniq[j+1][u];
            }
        }
        return res;
    }
};