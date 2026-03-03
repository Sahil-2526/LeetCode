class Solution {
public:
    int binaryGap(int n) {
        int prev=0;
        int curr=0;
       int gap=0;
       for(int i=1;n>0;i++){
        if(n%2 !=0){
            if(prev==0){
                prev=i;
            }
            else{
                curr=i;
                if(gap<curr-prev){
                    gap=curr-prev;
                }
                prev=i;
            }
        }
        n=n/2;
       }
       return gap;
    }
};