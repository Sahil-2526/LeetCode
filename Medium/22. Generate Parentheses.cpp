class Solution {
public:

    void generate(string curr,int l,int k, vector<string>& res){
        if(l==0 && k==0) res.push_back(curr);
        if(l>0) generate(curr+')', l-1, k, res);
        if(k>0) generate(curr+'(', l+1, k-1, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("(", 1, n-1, res);
        return res;
    }
};