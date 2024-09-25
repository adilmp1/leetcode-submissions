    int minOperations(vector<int>& a, int k) 
    {
        int xr=k;
        for(auto i:a) xr^=i;
        int cnt=0;
        while(xr)
        {
            cnt+=(xr%2)==1;
            xr/=2;
        }
        return cnt;
    }
