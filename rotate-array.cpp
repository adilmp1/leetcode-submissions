    void rotate(vector<int>& a, int k) 
    {
        int n = a.size();
        k%=n;
        if(!k) return;
        vector<int> ans;
        int idx = n-k;
        for(int i=idx;i<n;i++)
        {
            ans.push_back(a[i]);
        }
        for(int i=0;i<idx;i++)
        {
            ans.push_back(a[i]);
        }
        a = ans;
    }
