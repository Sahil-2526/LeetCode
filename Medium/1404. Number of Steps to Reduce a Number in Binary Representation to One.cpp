#include <climits>
class Solution {
public:
    int numSteps(string s) {
        int x=s.length();
        int count=0;
        while(x>1){
            if(s[x-1]=='0'){
                count++;
                s.pop_back();
                x--;
            }
            else{
                count+=2;
                s.pop_back();
                x--;
                bool k=false;
                   for(int i = x- 1; i >= 0; i--) {
        if(s[i] == '0') {
            s[i] = '1';
            k=true;
            break;
        }
            else{
                 s[i] = '0';
                       }}
            if(k==false){
                s='1'+s;
                x++;
            }
            }
        }
        return count;
    }
};