class Solution {
public:
    bool check(vector<long long> &arr, int k, int side, int mid){
        int n=arr.size();
        long long L= 4LL * side;
        vector<long long> extended(2*n);
        for(int i=0;i<n;i++){
            extended[i]=arr[i];
            extended[i+n]=arr[i]+L;
        }
        for(int i=0;i<n;i++){
            int count=1;
            long long pos = extended[i];
            int idx=i;
            for(int cnt=1;cnt<k;cnt++){
                long long target=pos+mid;
                auto it = lower_bound(extended.begin()+idx+1, extended.begin()+i+n,target);
                if(it==extended.begin()+i+n){
                    count=-1;
                    break;
                }
                idx=it-extended.begin();
                pos=extended[idx];
                count++;
            }
            if(count==k && (extended[i]+L-pos) >= mid) return true;
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;
        for(auto &p:points){
            int x=p[0],y=p[1];
            if(y==0) arr.push_back(x);
            else if(x==side) arr.push_back(side+y);
            else if(y==side) arr.push_back(2LL*side + (side-x));
            else arr.push_back(3LL*side + (side-y));
        }
        sort(arr.begin(),arr.end());

        int lo=0,hi=2*side,ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(arr,k,side,mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};