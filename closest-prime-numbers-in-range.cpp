    bool isPrime(int n) {
        if (n <= 1) return false;         
        if (n <= 3) return true;         
        if (n % 2 == 0 || n % 3 == 0) return false; 

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }


    vector<int> closestPrimes(int left, int right) {
        int lastPrime = -1;
        int diff = INT_MAX;
        vector<int> ans = {-1,-1};
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i))
            {
                if(lastPrime==-1)
                {
                    lastPrime = i;
                    continue;
                }
                if(i-lastPrime < diff)
                {
                    ans[0] = lastPrime;
                    ans[1] = i;
                    diff = i-lastPrime;
                    if(diff==1 or diff==2) return ans;
                }
                lastPrime = i;
            }
        }
        return ans;
    }
