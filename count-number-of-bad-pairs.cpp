    long long nc2(int n)
    {
        long long ans = n;
        ans*=ans-1;
        ans/=2;
        return ans;
    }
    long long countBadPairs(vector<int>& a) {
        unordered_map<int,int> mp;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            mp[i-a[i]]++;
        }
        long long ans = nc2(n);
        for(auto & pair:mp)
        {
            if(pair.second>1)
            {
                long long val = nc2(pair.second);
                ans-=val;
            }
        }
        return ans;
    }
