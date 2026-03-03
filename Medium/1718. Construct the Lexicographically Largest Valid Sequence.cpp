class Solution {
public:
    bool solve(int idx, vector<int>& ans, vector<bool>& used, int n) {
        if (idx == ans.size())
            return true;
        if (ans[idx] != 0)
            return solve(idx + 1, ans, used, n);
        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;
            if (num == 1) {
                ans[idx] = 1;
                used[1] = true;
                if (solve(idx + 1, ans, used, n))
                    return true;
                ans[idx] = 0;
                used[1] = false;
            }
            else {
                if (idx + num < ans.size() && ans[idx + num] == 0){
                    ans[idx] = num;
                    ans[idx + num] = num;
                    used[num] = true;
                    if (solve(idx + 1, ans, used, n))
                        return true;
                    ans[idx] = 0;
                    ans[idx + num] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,0);
        vector<bool> used(n+1, false);
        solve(0, ans, used, n);
        return ans;
    }
};