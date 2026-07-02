class Solution {
public:
    bool isPalindrome(string s) {
        string newstr = "";
        for(char c: s){
            if(isalpha(c)) newstr += tolower(c);
            else if(isdigit(c)) newstr += c;
        }
        int n = newstr.length();
        for(int i=0;i < n/2; i++){
            if( newstr[i] != newstr[n-i-1]) return false;
        }
        return true;
    }
};