    bool isOdd(int n)
    {
        int val = n%2;
        return (val==1);
    }
    int numOfSubarrays(vector<int>& a) 
    {
        long long mod = 1e9+7;
        int n = a.size();
        if(n==1) return (isOdd(a[0]));
        vector<int> dp(n,0);
        dp[0]=(isOdd(a[0]));
        if(dp[0])
        {
            dp[1]=2;
        }
        else
        {
            dp[1]=2*isOdd(a[1]);
        }
        for(int i=2;i<n;i++)
        {
            int x = dp[i-1]-dp[i-2];
            if(!isOdd(a[i]))
            {
                dp[i] = (dp[i-1]+x)%mod;
            }
            else
            {

                dp[i] = dp[i-1]%mod;
                dp[i] = (dp[i]+1)%mod;
                dp[i] = (dp[i]+i)%mod;
                dp[i] = (dp[i]-x)%mod;
            }
        }
        return dp[n-1];
    }
