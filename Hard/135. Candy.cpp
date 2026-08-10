class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        map<int,vector<int>> idx;
        for(int i=0; i<n; i++){
            idx[ratings[i]].push_back(i);
        }
        vector<int> candy(n,0);
        for (auto &[val, idxs] : idx) {
            for(auto x: idxs){
                int val = 0;
                if(x-1 >= 0 && ratings[x] > ratings[x-1]) val = max(val, candy[x-1]);
                if(x+1 < n && ratings[x] > ratings[x+1]) val = max(val, candy[x+1]);
                candy[x] = val+1;
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};