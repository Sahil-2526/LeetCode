class Solution {
public:
    vector<string> chars = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> res;

    void solve(int i, string ans, string digits) {
        if(i == digits.size()) {
            res.push_back(ans);
            return;
        }
        for(char x : chars[digits[i] - '0']) {
            solve(i+1, ans+x, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(0, "", digits);
        return res;
    }
};