#include<algorithm>
class Solution {
public:
    int minOperations(string s) {
        int zo=0;
        int oz=0;
        for(int i=0;i<s.length();i++){
            if(i%2==0){
                if(s[i]=='0') zo++;
                else oz++;
            }
            else{
                if(s[i]=='1') zo++;
                else oz++;
            }
        }
        return min(zo,oz);
    }
};