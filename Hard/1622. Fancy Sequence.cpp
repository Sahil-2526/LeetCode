class Fancy {
private:
    long long ad;
    long long mul;
    vector<long long> nums;
    const long long mx= 1000000007;
    long long modPow(long long a,long long b){ // it finds a^b % mx using binary exponentiation
        long long res = 1;
        while(b){
            if(b&1) res = (res*a)%mx;
            a = (a*a)%mx;
            b >>= 1;
        }
        return res;
    }
public:
    Fancy() {
        nums = vector<long long>();
        ad=0;
        mul=1;
    }
    
    void append(long long val) {
        val=(val-ad+mx)%mx;
        long long inv = modPow(mul, mx-2);
        val=(val*inv)%mx;
        nums.push_back(val);
    }
    
    void addAll(int inc) {
        ad=(ad+inc)%mx;
    }
    
    void multAll(int m) {
        ad=(ad*m)%mx;
        mul=(mul*m)%mx;
    }
    
    int getIndex(int idx) {
        if(idx>=nums.size() || idx<0) return -1;
        return (nums[idx]*mul%mx + ad)%mx;;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */



 //to decrease the complexity instead of always updating the numbers we store 2 variable ad and mul
 //every time getIndex is called the value will be in form - nums[i]*mul + ad -> so that we don't have to compute the value every time
 //when we append value ve insert it in form (val-ad)/mul so that ad and mul can work on that too
 //while using %MAX a/b is not computed properly so we use MODULAR MULTIPLICATIVE INVERSE
 // a/b % m = a* b^(m-2) % m (when m is prime) -> so we use modPow to calculate that inverse and then multiply it with val to get the correct value in append function
 // in modPow function , if we want to do a^6 
 // 6 -> 110 in binary  res=1 -> res=res*a^2 -> res=res*a^4
 // we multiply in parts because power is too high 
