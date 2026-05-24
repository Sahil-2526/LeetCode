class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size( );
        multiset<pair<int,int>> pos; 
        for( int i = 0; i < n; i++){
            pos.insert({arr[i], i});
        }
        vector<int> baigan(n,0);
        for( auto [value, idx] : pos){
            int val = 0;
            for( int i = 1; i <= d ; i ++){
                if(idx+i < n && arr[idx+i] < value ) val = max(val, baigan[idx+i]);
                else break;
            }
            for( int i = 1; i <= d ; i ++){
                if(idx-i >= 0 && arr[idx-i] < value ) val = max(val, baigan[idx-i]);
                else break;
            }
            baigan[idx] = val + 1;
        }
        int res = 0;
        for( int i = 0; i < n ; i++){
            res = max( res, baigan[i]);
        }
        return res;
    }
};