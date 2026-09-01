class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string word = "";
        int n = s.length();

        for(int i=0; i<n; i++){
            if(s[i] == ' '){
                if(word != ""){
                    if(res != "") res = word + " " + res;
                    else res = word;
                    word = "";
                }
            }
            else word += s[i];
        }

        if(word != ""){
            if(res != "") res = word + " " + res;
            else res = word;
        }

        return res;
    }
};