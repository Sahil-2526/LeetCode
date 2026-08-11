class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int lsp = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1) break;
            lsp += nums[i];
        }
        set<int> st;
        for(int x : nums){
            st.insert(x);
        }
        while(st.count(lsp)){
            lsp++;
        }
        return lsp;
    }
};