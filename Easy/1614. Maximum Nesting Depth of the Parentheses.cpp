class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int b = 0;
        for(char c: s){
            if(c == '(')
                b++;
            else if(c == ')')
                b--;
            res = max(b, res);
        }

        return res;
    }
};