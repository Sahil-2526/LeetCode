class Solution {
public:

    pair<int, int> generate(string s, int i) {
        int val = 0;

        while(i < s.length()) {
            if(s[i] == '(') {
                auto p = generate(s, i+1);
                val += p.first;
                i = p.second;
            }
            else {
                if(val == 0) val += 1;
                else val *= 2;
                return {val, i + 1};
            }
        }
        return {val, i};
    }

    int scoreOfParentheses(string s) {
        return generate(s, 0).first;
    }
};