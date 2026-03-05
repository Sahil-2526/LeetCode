class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int l=word.length();
        int count=0;
        for(int i=0;i<l-1;i++){
            if( word[i]-'a'==word[i+1]-'a' || word[i]-'a'==word[i+1]-'a'-1 || word[i]-'a'==word[i+1]-'a'+1){
                 count++;
                 i++;
            }
        }
        return count;
    }
};