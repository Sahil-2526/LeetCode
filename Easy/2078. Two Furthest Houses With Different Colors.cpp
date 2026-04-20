class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        
        for (int i = 0; i < n; i++) {
            if (colors[0] != colors[n - 1 - i])
                return n - 1 - i;
            
            if (colors[n - 1] != colors[i])
                return n - 1 - i;
        }
        
        return 0;
    }
};