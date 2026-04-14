class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());

        int curr = left;

        for (auto &r : ranges) {
            if (r[1] < curr) continue;    
            if (r[0] > curr) return false; 
            curr = max(curr, r[1] + 1);    
            if (curr > right) return true; 
        }

        return curr > right;
    }
};