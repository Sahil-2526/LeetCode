class Solution { 
public: 
    int totalFruit(vector<int>& fruits) { 
        int n = fruits.size(); 
        if(n <= 2) return n;
        
        int b1=fruits[0], b2=-1; 
        int f1=0, f2=-1; 
        int last = 0; 
        int mx = 1; 
        
        for(int i=1; i<n; i++){ 
            if(fruits[i]!= b1 && fruits[i]!=b2){ 
                if(b2 == -1){
                    b2 = fruits[i];
                    f2 = i;
                }
                else{
                    last = min(f1, f2) + 1;
                    
                    if(f1 < f2){ 
                        f1 = i; 
                        b1 = fruits[i]; 
                    } 
                    else{ 
                        f2 = i; 
                        b2 = fruits[i]; 
                    } 
                }
            } 
            
            if(fruits[i] == b1) f1 = i; 
            if(fruits[i] == b2) f2 = i; 
            
            mx = max(mx, i-last+1); 
        } 
        return mx; 
    } 
};