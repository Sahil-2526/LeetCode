class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> lmm;
        int prev = head->val;
        head = head->next;
        int i=1;
        while(head->next!=NULL){
            int val = head->val;
            if(prev > val && head->next->val > val 
                || prev < val && head->next->val < val )  
                lmm.push_back(i);
            head = head->next;
            prev = val;
            i++;
        }
        int n = lmm.size();
        if(n <= 1) return {-1, -1};
        int mn = INT_MAX;
        for(int i=1; i<n; i++){
            mn = min(mn, lmm[i]-lmm[i-1]);
        }
        int mx = lmm[n-1]-lmm[0];
        return {mn, mx};
    }
};