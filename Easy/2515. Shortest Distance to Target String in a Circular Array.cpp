class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startInd) {
        map<string,vector<int>>mpp;
        int n=words.size();
        for(int i=0;i<n;i++){
            mpp[words[i]].push_back(i);
        }
        int min_steps=1e9;
      
       for(auto ind:mpp[target]){
             min_steps=min({min_steps,abs(ind-startInd), n-abs(ind-startInd)});
       }
       int t=min_steps;
       if(t==1e9)return -1;
       return t;
    }
};