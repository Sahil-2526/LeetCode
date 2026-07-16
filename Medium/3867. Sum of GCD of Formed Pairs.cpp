class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        int n = nums.size();
        vector<int> prefixGCD(n);
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            prefixGCD[i] = gcd(nums[i], mx);
        }
        sort(prefixGCD.begin(), prefixGCD.end());
        long long sum = 0;
        int i=0;
        int j=n-1;
        while(i<j){
            sum += gcd(prefixGCD[i], prefixGCD[j]);
            i++;
            j--;
        }
        return sum;
    }
};