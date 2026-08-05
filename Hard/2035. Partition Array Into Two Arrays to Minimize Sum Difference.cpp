class Solution {
public:
    typedef long long ll;
    unordered_map<int,vector<ll>> lseq, rseq;

    void subseqSum(int idx, int count, ll sum, vector<int>& arr, bool left){
        if(idx == arr.size()){
            if(left) lseq[count].push_back(sum);
            else rseq[count].push_back(sum);
            return;
        }

        // Taking current element
        subseqSum(idx+1, count+1, sum+arr[idx], arr, left);

        // Not taking current element
        subseqSum(idx+1, count, sum, arr, left);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n /= 2;

        // Finding total sum of all elements
        ll total = 0;
        for(int x : nums){
            total += x;
        }

        // If total sum is 12 and its half is 6,
        // i have to find a subsequence sum most closes to 6
        // (either greater or smaller) to make the difference minimum
        ll sum = total / 2;

        // Dividing array
        vector<int> larr, rarr;
        for(int i = 0; i < n; i++){
            larr.push_back(nums[i]);
            rarr.push_back(nums[i+n]);
        }

        // Making left and right subsequence sums
        subseqSum(0, 0, 0, larr, true);
        subseqSum(0, 0, 0, rarr, false);

        // Sorting right subsequence sum arrays
        for(int i = 0; i <= n; i++){
            sort(rseq[i].begin(), rseq[i].end());
        }

        // Iterating through every value of left subsequence sum
        // and finding best possible right subsequence sum
        ll ans = LLONG_MAX;

        for(int i = 0; i <= n; i++){
            int ri = n - i;

            for(ll x : lseq[i]){

                // Ideal right subsequence sum required
                ll idl_rval = sum - x;

                auto it = lower_bound(rseq[ri].begin(), rseq[ri].end(), idl_rval);

                // Checking the first value >= ideal value
                if(it != rseq[ri].end()){
                    ll new_sum = x + *it;
                    ans = min(ans, llabs(total - 2 * new_sum));
                }

                // Checking the previous value (< ideal value)
                if(it != rseq[ri].begin()){
                    --it;
                    ll new_sum = x + *it;
                    ans = min(ans, llabs(total - 2 * new_sum));
                }
            }
        }

        return (int)ans;
    }
};