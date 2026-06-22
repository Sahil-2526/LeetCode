class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> count(26,0);
        vector<int> freq(26,0);
        for(char x: s) count[x - 'a']++;
        for(char x: target) freq[x - 'a']++;
        int inst = INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i] != 0) inst = min(inst, count[i]/freq[i]);
        }
        return inst;
    }
};