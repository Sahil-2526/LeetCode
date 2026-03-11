class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v(n+1);
        v[0]=0;
        if(n>=1) v[1]=1;
        int val=1;
        for(int i=2;i<=n;i++){
            if(i==val*2) val=i;
            v[i]=v[i-val]+1; }
        return v;
    }
};