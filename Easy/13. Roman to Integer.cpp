#include <unordered_map>
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int len=s.length();
        int count=0;
        for(int i=0;i<len;i++){
            if(i==0 || mp[s[i-1]]>=mp[s[i]]) count+=mp[s[i]];
            else{
                count+=(mp[s[i]]-2*mp[s[i-1]]);
            }
        }
        return count;
    }
};