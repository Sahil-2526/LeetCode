class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sorting cookie and greed array
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int g_size = g.size();
        int s_size = s.size();

        // Assign the smallest cookie to child whose size is >= greed
        int gp = 0;
        int sp = 0;
        int childs = 0;
        while( gp<g_size && sp<s_size){
            if(g[gp] <= s[sp]){
                childs++;
                gp++;
                sp++;
            }
            else sp++;
        } 

        return childs;
    }
};