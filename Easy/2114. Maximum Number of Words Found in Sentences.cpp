class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int len=sentences.size();
        int result=0;
        for(int i=0;i<len;i++){
            int count=1;
            int l=sentences[i].size();
            for(int j=0;j<l;j++){
                if(sentences[i][j]==' ') count++;
            }
            result=max(count,result);
        }
        return result;
  
    }
};