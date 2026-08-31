class Solution { 
public: 
    long long sumOfRange(long long a, long long b) { 
        return ((b-a+1)*(a+b))/2; 
    } 
    int maxProfit(vector<int>& inventory, int orders) { 
        const long long MOD = 1e9+7;
        sort(inventory.begin(), inventory.end()); 
        long long cost = 0; 
        int n = inventory.size(); 
        long long mx = inventory[n-1]; 
        int i = n-1; 
        int j = n-1; 
        while(orders > 0) { 
            while(i >= 0 && inventory[i] == mx) i--; 
            long long abc = i >= 0 ? inventory[i] : 0; 
            long long canachieve = (j-i)*(mx-abc);
            if(orders >= canachieve) { 
                orders -= canachieve; 
                cost = (cost+sumOfRange(abc+1, mx) * (j-i))%MOD; 
                mx = abc; 
            } 
            else { 
                long long nr = orders/(j-i); 
                long long nc = orders%(j-i); 
                orders = 0; 
                cost = (cost+sumOfRange(mx-nr+1, mx) * (j-i))%MOD; 
                mx = mx-nr; 
                cost = (cost+mx*nc)%MOD;
            } 
        } 
        return cost % MOD; 
    } 
};