    vector<int> a;
    ProductOfNumbers() {
        
    }
    
    void add(int n) {
        a.push_back(n);
    }
    
    int getProduct(int k) {
        int n = a.size();
        long long product=1;
        for(int i=n-k;i<n;i++)
        {
            product*=a[i];
        }
        return product;
    }
