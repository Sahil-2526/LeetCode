class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        int count=0;
        if(n==1) return 0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                int i=q.front();
                q.pop();
                if(i+nums[i]>=n-1) return ++count;
                for(int j=nums[i];j>0;j--){
                    if(!vis[i+j]){
                        q.push(i+j);
                        vis[i+j]=true;
                    }
                }
            }
            count++;
        }
        return count;
    }
};