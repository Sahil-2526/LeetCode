class ProductOfNumbers {
public:
    vector<long long> prod;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0) prod.clear();
        else{
            if(prod.size() == 0) prod.push_back(num);
            else prod.push_back(prod.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n = prod.size();
        if(k > n) return 0;
        if(k == n) return prod[n-1];
        return (int)prod[n-1] / prod[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */