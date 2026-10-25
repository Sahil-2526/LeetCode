class Solution {
public:
    int ones(int num){
        int count = 0;
        while(num){
            num &= (num-1); 
            count++;
        }
        return count;
    }
    int calculateScore(int a, int b) {
        int s1 = ones(a);
        int s2 = ones(b);
        if(s1 >= s2) return s1*s2;
        return s2/s1;
    }
};