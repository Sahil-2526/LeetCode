class Solution {
public:
    typedef long long ll;
    ll rearrange(ll n){
        vector<int> arr(10, 0);
        while(n){
             arr[n%10]++;
             n = n/10;
        }
        ll res = 0;
        for(int i=9; i>=0; i--){
            while(arr[i] != 0){
                res = res*10 + i;
                arr[i]--;
            }
        }
        return res; 
    } 
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<ll, ll> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]] = rearrange(nums[i]);
        }
        sort(nums.begin(), nums.end(), [&](auto a, auto b){
            return mp[a]-a > mp[b]-b;
        });
        
        long long res = 0;
        for(int i=0; i<n; i++){
            if(k>0){
                res += mp[nums[i]];
                k--;
            }
            else res += nums[i];
        }
        return res;
    }
};