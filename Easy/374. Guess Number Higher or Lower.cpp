/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long l=1, r=n;
        while(l <= r){
            long long mid = floor(l+(r-l)/2);
            int gs = guess(mid);
            if(gs == 0) return mid;
            else if(gs == 1) l = mid+1;
            else r = mid-1;
        }
        return r;
    }
};