    int subsetXORSum(vector<int>& a) 
    {
        int n = a.size();
        int ans=0;
        for(int i=0;i<(1<<n);i++)
        {
            int xr = 0;
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j))
                {
                    xr^=a[j];
                }
            }
            ans+=xr;
        }    
        return ans;
    }
