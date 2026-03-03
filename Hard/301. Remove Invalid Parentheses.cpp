#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        int left_remove = 0, right_remove = 0;
        for (char ch : s) {
            if (ch == '(') {
                left_remove++;
            } else if (ch == ')') {
                if (left_remove > 0) {
                    left_remove--;
                } else {
                    right_remove++;
                }
            }
        }
        function<void(int,int,int,int,int,string)> backtrack = [&](int index, int left_count, int right_count, int l_rem, int r_rem, string path) {
            if (index == s.size()) {
                if (l_rem == 0 && r_rem == 0 && isValid(path)) {
                    result.push_back(path);
                }
                return;
            }
            char ch = s[index];
            if (ch == '(') {
                if (l_rem > 0)
                    backtrack(index + 1, left_count, right_count, l_rem - 1, r_rem, path);\
                backtrack(index + 1, left_count + 1, right_count, l_rem, r_rem, path + ch);
            }
            else if (ch == ')') {
                if (r_rem > 0)
                    backtrack(index + 1, left_count, right_count, l_rem, r_rem - 1, path);
                if (left_count > right_count)
                    backtrack(index + 1, left_count, right_count + 1, l_rem, r_rem, path + ch);
            }
            else {
                backtrack(index + 1, left_count, right_count, l_rem, r_rem, path + ch);
            }
        };
        backtrack(0, 0, 0, left_remove, right_remove, "");
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
private:
    bool isValid(const string &s) {
        int balance = 0;
        for (char ch : s) {
            if (ch == '(') balance++;
            else if (ch == ')') {
                if (balance == 0) return false;
                balance--;
            }
        }
        return balance == 0;
    }
};