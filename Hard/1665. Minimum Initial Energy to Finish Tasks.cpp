class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return (a[1]-a[0])>(b[1]-b[0]);
        });
        int n=tasks.size();
        int req=0;
        int left=0;
        for(int i=0;i<n;i++){
            if(left<tasks[i][1]){
                req+=(tasks[i][1]-left);
                left=tasks[i][1];
            }
            left-=tasks[i][0];
        }
        return req;
    }
};