class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0;
        int n = cost.size();
        sort(cost.begin(),cost.end());
        for(int i = n-1; i>=0; i--){
            if((n-i) % 3 != 0 ) res+=cost[i];
        }
        return res;
    }
};