class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> prefixes;
        for(int x : arr1){
            while(x>0){
                prefixes.insert(x);
                x=x/10;
            }
        }
        int maxm=0;
        for(int x : arr2){
            while(x>0){
                if(prefixes.find(x)!=prefixes.end()){
                    maxm=max(maxm,x);
                    break;
                }
                x=x/10;
            }
        }
        int count=0;
        while(maxm>0){
            count++;
            maxm=maxm/10;
        }
        return count;
    }
};