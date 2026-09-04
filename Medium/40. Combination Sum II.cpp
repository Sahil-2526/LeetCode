class Solution {
public:
    vector<vector<int>> res;

    void generate(int sm, vector<int> num, int i, int target, vector<int>& c) {
        if (sm == target) {
            res.push_back(num);
            return;
        }
        for (int j = i + 1; j < c.size(); j++) {
            if (j > i+1 && c[j] == c[j-1]) continue;
            if (sm+c[j] > target) break;
            num.push_back(c[j]);
            generate(sm + c[j], num, j, target, c);
            num.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        generate(0, {}, -1, target, candidates);
        return res;
    }
};