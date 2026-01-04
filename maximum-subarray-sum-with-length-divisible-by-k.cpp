    long long maxSubarraySum(vector<int>& a, int k) {
        long long ans = LLONG_MIN;
        vector<long long> mp(k,LLONG_MAX);
        mp[k-1]=0;
        long long prefixSum=0;
        for(int i=0;i<a.size();i++)
        {
            int mod = i%k;
            prefixSum+=a[i];
            if(mp[mod]!=LLONG_MAX) ans = max(ans,prefixSum-mp[mod]);
            mp[mod] = min(mp[mod],prefixSum);
        }
        return ans;
    }
