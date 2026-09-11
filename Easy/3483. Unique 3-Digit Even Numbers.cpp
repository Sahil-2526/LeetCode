class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        int res = 0;

        for(int x: digits)
            cnt[x]++;
            
        for(int i=1; i<10; i++){
            if(cnt[i] == 0)
                continue;
            cnt[i]--;
            for(int j=0; j<10; j++){
                if(cnt[j] == 0)
                    continue;
                cnt[j]--;
                for(int k=0; k<10; k+=2){
                    if(cnt[k] > 0)
                        res++; 
                }
                cnt[j]++;
            }
            cnt[i]++;
        }

        return res;
    }
};