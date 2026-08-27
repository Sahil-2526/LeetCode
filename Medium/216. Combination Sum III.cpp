class Solution {
public:
    vector<vector<int>> res;
    int sum;
    void solve(int i,int sm, int k, vector<int> val){
        if(k == 0){
            if(sm == sum) res.push_back(val);
        }
        else{
            if(sm >= sum || i == 10) return;
            solve(i+1, sm, k, val);
            val.push_back(i);
            solve(i+1, sm+i, k-1, val);
        }
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k*(k-1)/2 > n) return {};
        sum = n;
        solve(1, 0, k, {});
        return res;
    }
};