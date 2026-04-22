class Solution {
public:
    bool isSimilar(string a,string b,int n){
        int diff=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) diff++;
            if(diff>2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        int k=queries[0].length();

        vector<string> result;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isSimilar(queries[i],dictionary[j],k)){
                    result.push_back(queries[i]);
                    break;
                }
            }
        }

        return result;
    }
};