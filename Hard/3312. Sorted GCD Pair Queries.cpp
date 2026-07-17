class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> count(mx+1, 0);
        for(int x: nums) count[x]++;

        vector<long long> gcdPairs(mx+1,0);
        for(int i=1; i<=mx; i++){
            long long x = 0;
            for(int j=i; j<=mx; j+=i){
                x += count[j];
            }
            gcdPairs[i] = (x*(x-1)) / 2; 
        }
        
        for(int i=mx; i>=1; i--){
            for(int j=2*i; j<=mx; j+=i){
                gcdPairs[i] -= gcdPairs[j];
            }
        }

        vector<long long> preSum(mx+1);
        for(int i=1; i<=mx; i++){
            preSum[i] = preSum[i-1] + gcdPairs[i];
        }

        int m = queries.size();
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            long long k = queries[i];
            int l = 1, r = mx;
            while(l < r){
                int mid = l + (r-l)/2;
                if(preSum[mid] > k) r = mid;
                else l = mid+1;
            }
            ans[i] = l;
        }
        return ans;
    }
};