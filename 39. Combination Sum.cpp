class Solution {
public:
    vector<vector<int>> res;
    void generate(int sm, vector<int> num, int i, int target, vector<int>& c){
        if(sm == target) res.push_back(num);
        else if(sm > target) return;
        else{
            for(int j=i; j<c.size(); j++){
                num.push_back(c[j]);
                generate(sm+c[j], num, j, target, c);
                num.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for(int i=0; i<candidates.size(); i++){
            generate(candidates[i], {candidates[i]}, i, target, candidates);
        }
        return res;
    }
};