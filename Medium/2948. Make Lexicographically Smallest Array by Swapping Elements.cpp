class Solution { 
public: 
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) { 
        int n = nums.size(); 
        vector<int> idx(n); 
        for(int i=0; i<n; i++) idx[i]=i; 
 
        sort(idx.begin(), idx.end(), [&](int a, int b){ 
            return nums[a] < nums[b]; 
        }); 

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end()); 
 
        vector<int> gap; 
        for(int i=0; i<n-1; i++){ 
            if(sorted[i+1]-sorted[i] > limit) gap.push_back(i); 
        } 

        int init = 0; 
        for(int end=0; end<gap.size(); end++){ 
            sort(idx.begin()+init, idx.begin()+gap[end]+1); 
            init = gap[end]+1; 
        }
        sort(idx.begin()+init, idx.end());

        vector<int> res(n); 
        int start = 0;
        for(int i=0; i<=gap.size(); i++){ 
            int end = (i < gap.size() ? gap[i]+1 : n);
            for(int j=start; j<end; j++){ 
                res[idx[j]] = sorted[j]; 
            }
            start = end;
        }

        return res; 
    } 
};