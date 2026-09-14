class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(1LL * m * k > n)
            return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        while(l < r) {
            int mid = l + (r - l) / 2;

            int flowers = 0;
            int bouquets = 0;

            for(int i = 0; i < n; i++) {
                if(bloomDay[i] <= mid) {
                    flowers++;

                    if(flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                }
                else {
                    flowers = 0;
                }
            }

            if(bouquets >= m)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};