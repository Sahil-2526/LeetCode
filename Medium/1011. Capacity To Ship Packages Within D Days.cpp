class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l=*max_element(weights.begin(), weights.end());
        int r=accumulate(weights.begin(), weights.end(), 0);
        int res = r;
        while(l<=r){
            int mid = l+(r-l)/2;
            int count = 0;
            int sum = 0;
            for(int i=0; i<n; i++){
                if(sum+weights[i] > mid){
                    sum = weights[i];
                    count++;
                }
                else{
                    sum += weights[i];
                }
            } 
            if(sum > 0) count++;
            if(count <= days){
                res = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        return res;
    }
};