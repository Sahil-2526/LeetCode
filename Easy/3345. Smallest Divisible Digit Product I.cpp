class Solution {
public:
    // Function to find product of digits
    int prod_of_dig(int num){
        string s = to_string(num);
        int prod = 1;
        for(char c: s){
            prod *= (c-'0');
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int i=n;

        // Start from n and keep going until you found one 
        while(prod_of_dig(i)%t != 0) i++;
        
        return i;
    }
};