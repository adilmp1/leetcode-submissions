    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        long long ans=0;
        int count=0;
        int minimumLoss = INT_MAX;
        for(int i:nums)
        {
            int xr = (i^k);
            ans+=max(i,xr);
            minimumLoss = min(minimumLoss,abs(i-xr));
            if(i<xr)
            {
                count++;
            }
        } 
        if((count&1)==1) ans-=minimumLoss;
        return ans;
    }
