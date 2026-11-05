class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;
        for(int i=0; i<n; i++){
            int l = 0, r = m-1;
            bool maybe = true;
            while(l<r){
                int mid = l+(r-l)/2;
                if(arr2[mid] == arr1[i]){
                    maybe = false;
                    break;
                }
                if(arr2[mid] > arr1[i]) r = mid;
                else l = mid+1;
            }
            if(maybe){
                if(abs(arr2[l]-arr1[i]) > d){
                    if(l==0 || (l>0 && abs(arr2[l-1]-arr1[i]) > d)) count ++;
                }
            }
        }
        return count;
    }
};