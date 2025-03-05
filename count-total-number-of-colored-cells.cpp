    long long coloredCells(int n) 
    {
        long long ans=1;
        int k  = 4;
        for(int i=1;i<n;i++)
        {
            ans+=4*i;
        }    
        return ans;
    }
