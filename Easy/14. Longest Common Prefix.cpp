class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char first=strs[0][0];
        int n=strs.size();
        int j=0;
        string result="";
        while(1){
            for(int i=0;i<n;i++){
                if(strs[i][j]!= first || j>=strs[i].length()) return result;
            }
            result+=first;
            j++;
            first=strs[0][j];
        }
        return result;
    }
};