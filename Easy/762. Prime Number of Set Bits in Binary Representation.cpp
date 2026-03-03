class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        int num=0;
        int arr[]={2,3,5,7,11,13,17,19};
        for(int i=left;i<=right;i++){
            for(int j=1;j<=20;j++){
                int l=pow(2,j);
                if(i%l>=l/2 && i%l<l){
                    num++;
                }
            }
            for(int k=0;k<8;k++){
                if(arr[k]==num){
                count++; }
            }
            num=0;
        }
        return count;
    }
};