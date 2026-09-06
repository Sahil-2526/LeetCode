class Solution {
public:
    typedef unsigned long long ll;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<ll> nums(n,0);
        for (int j = n-1; j >= 0; j--) {
            if (s[j] == t[m-1])
                nums[j] = 1;
        }

        for(int i=m-2; i>=0; i--){
            ll count = 0;
            for(int j=n-1; j>=0; j--){
                ll val = count;
                if(s[j] == t[i+1]) count += nums[j];
                if(s[j] == t[i]) nums[j] = val;
            }
        }

        ll res = 0;
        for(int i=0; i<n; i++){
            if(s[i] == t[0]) res += nums[i]; 
        }

        return res;
    }
};