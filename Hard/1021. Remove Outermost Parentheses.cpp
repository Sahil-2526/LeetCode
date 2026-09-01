class Solution {
public:
    string removeOuterParentheses(string s) {
        bool find_close = false;
        string res;
        int valid = 0;
        for(char c: s){
            if(find_close == false){
                if(c == '('){
                    find_close = true;
                    continue;
                }
            }
            else{
                if(valid == 0){
                    if(c == ')'){
                        find_close = false;
                        continue;
                    }
                }
                res += c;
                if(c == '(') valid++;
                else valid--;
            }
        }
        return res;
    }
};