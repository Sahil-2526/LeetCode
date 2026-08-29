class Solution {

public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int mx = 0;

        for(int c=0; c<26; c++){
            int last = 0;
            int kd = k;
            for(int i=0; i<n; i++){
                if(s[i]-'A' != c){
                    if(kd > 0) kd--;
                    else{
                        while(s[last]-'A' == c) last++;
                        last++;
                    }
                }

                mx = max(mx, i-last+1);
            }
        }

        return mx;
    }
};