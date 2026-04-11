class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> pos(n);
        int k=0;
        unordered_map<int,int> index;
        unordered_map<int,int> count;
        int ans = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(count[nums[i]]<1){
                pos[k].push_back(i);
                index[nums[i]]=k;
                k++;
                count[nums[i]]++;
            }
            else if(count[nums[i]]<3){
                pos[index[nums[i]]].push_back(i);
                count[nums[i]]++;
                if(count[nums[i]]==3){
                    int idx=index[nums[i]];
                    int val=pos[idx][2]-pos[idx][0];
                    ans=min(ans,val);
                }
            }
            else{
                int idx=index[nums[i]];

                pos[idx][0]=pos[idx][1];
                pos[idx][1]=pos[idx][2];
                pos[idx][2]=i;

                int val=pos[idx][2]-pos[idx][0];
                ans=min(ans,val);
            }
        }
        
        return ans == INT_MAX ? -1 : 2*ans;
    }
};