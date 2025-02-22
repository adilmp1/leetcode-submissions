    int countMaxOrSubsets(vector<int>& a) 
    {
        int ans=0;
        int val = 0;
        for(int i:a) val|=i;
        int n = a.size();
        for(int i=0;i<(1<<n);i++)
        {
            int curr = 0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    curr|=a[j];
                }
            }
            if(curr==val) ans++;
        }
        return ans;
    }
