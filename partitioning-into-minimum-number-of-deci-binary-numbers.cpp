    int minPartitions(string s) {
        int ans=0;
        for(auto c:s)
        {
            int n = c-'0';
            ans=max(ans,n);
        }
        return ans;
    }
