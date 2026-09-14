class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n) return -1;

        long long l = 1;
        long long r = *max_element(piles.begin(), piles.end());

        while(l < r) {
            long long mid = l + (r-l)/2;
            long long count = 0;

            for(int i = 0; i < n; i++) {
                count += (piles[i] + mid - 1) / mid;
            }

            if(count <= h)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};