    vector<int> a={1};
    int last_zero_idx=-1;
    ProductOfNumbers() {
        
    }
    
    void add(int n) {
        if(!n) last_zero_idx = a.size();
        if(!a.back()) a.push_back(n);
        else a.push_back(n*a.back());
    }
    
    int getProduct(int k) {
        int n = a.size();
        if(last_zero_idx!=-1 and last_zero_idx>=n-k) return 0;
        long long product=a.back();
        if(!a[n-k-1]) return product;
        return product/a[n-k-1];
    }
