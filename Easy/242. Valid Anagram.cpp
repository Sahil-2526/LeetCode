class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(int i=0; i<s.length(); i++){
            mp1[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            mp2[t[i]]++;
        }
        if(mp1.size() != mp2.size()) 
            return false;
        for(auto [a,b]: mp1){
            if(mp2[a] != b) 
                return false;
        }
        return true;
    }
};