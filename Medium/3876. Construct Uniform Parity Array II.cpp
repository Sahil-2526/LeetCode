class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2)
                hasOdd = true;
            else
                hasEven = true;
        }

        if (!hasOdd || !hasEven) return true;
        
        int minOdd = INT_MAX;

        for (int x : nums1) {
            if (x % 2)
                minOdd = min(minOdd, x);
        }

        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd)
                return false;
        }

        return true;
    }
};