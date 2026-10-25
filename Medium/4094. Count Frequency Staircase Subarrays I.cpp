class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i=0; i<n; i++){
            unordered_map<int, int> count;
            unordered_map<int, int> need;

            int j = i;
            int k = 0;
            int bd = 0;

            while(j < n){
                int val = nums[j];

                if(!need.count(val)){
                    k++;
                    need[val] = k;
                    count[val] = 0;
                    bd++;
                }

                if(count[val] != need[val])
                    bd--;

                count[val]++;

                if(count[val] != need[val])
                    bd++;

                if(count[val] > need[val])
                    break;

                if(bd == 0)
                    res++;

                j++;
            }
        }

        return res;
    }
};