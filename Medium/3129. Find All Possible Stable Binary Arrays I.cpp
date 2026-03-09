class Solution {
public:
    int M= 1e9 + 7;
    int t[201][201][2];
    int solve(int onesleft , int zerosleft , bool lastwasone ,int  limit){
        int result =0;
        if(onesleft == 0 && zerosleft == 0) return 1;
        if(t[onesleft][zerosleft][lastwasone] != -1) return t[onesleft][zerosleft][lastwasone];

        if(lastwasone == true){ 
            for(int len = 1; len<= min(limit,zerosleft);len++){
                result = (result + solve(onesleft , zerosleft-len,false,limit)) % M;
            }
        }
        else{ 
            for(int len =1 ; len<=min(limit,onesleft);len++){
                result = (result + solve(onesleft-len ,zerosleft,true,limit )) % M;
            }
        }
        t[onesleft][zerosleft][lastwasone]= result;
        return result;
        }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int stwithzero = solve(zero,one,true,limit);
        int stwithone = solve(zero , one,false,limit);
        return (stwithone + stwithzero) %M;
    }
};