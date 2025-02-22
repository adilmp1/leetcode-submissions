    vector<int> getMaximumXor(vector<int>& a, int maximumBit) 
    {
        vector<int> ans;
        int maxi = (1<<maximumBit)-1;
        int xr = 0;
        for(int i:a) xr^=i;
        for(int i=a.size()-1;i>=0;i--)
        {
            ans.push_back(xr^maxi);
            xr^=a[i];
        }   
        return ans;
    }
