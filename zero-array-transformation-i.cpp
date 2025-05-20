    bool isZeroArray(vector<int>& a, vector<vector<int>>& queries) 
    {
        int n = a.size();
        vector<int> temp(n,0);
        for(auto v:queries)
        {
            temp[v[0]]++;
            if(v[1]+1<n) temp[v[1]+1]--;
        }
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=temp[i];
            if(sum<a[i]) return false;
        }
        return true;
    }
