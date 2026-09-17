class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<pair<int, int>> inds;

        int l = 0, sum = 0;
        for(int r = 0; r < n; r++){
            sum += arr[r];
            while(sum > target){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                inds.push_back({l, r});
            }
        }

        int m = inds.size();
        if(m < 2)
            return -1;

        vector<int> nextIdx(m, -1);
        for(int i = 0; i < m; i++){
            int li = i+1, ri = m-1;
            while(li <= ri){
                int mid = li + (ri - li) / 2;
                if(inds[mid].first > inds[i].second)
                    ri = mid-1;
                else
                    li = mid+1;
            }
            if(li != m)
                nextIdx[i] = li;
        }

        vector<int> minm(m);
        minm[m-1] = inds[m-1].second - inds[m-1].first + 1;
        for(int i = m-2; i >= 0; i--){
            int len = inds[i].second - inds[i].first + 1;
            minm[i] = min(minm[i+1], len);
        }

        int res = INT_MAX;
        for(int i = 0; i < m; i++){
            if(nextIdx[i] != -1){
                int len1 = inds[i].second - inds[i].first + 1;
                int len2 = minm[nextIdx[i]];
                res = min(res, len1 + len2);
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};