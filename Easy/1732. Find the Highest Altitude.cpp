class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> ps(n+1,0);
        for(int i=1; i<n+1; i++){
            ps[i] = ps[i-1]+gain[i-1];
        }
        return *max_element(ps.begin(),ps.end());
    }
};