const int mod = 1e9+7;
long long modPow(long long base, long long exp)
{
    long long ans=1;

    while(exp)
    {
        if(exp&1) ans= ans*base%mod;
        base=base*base%mod;
        exp>>=1;
    }
    return ans;
}

int maxPower(int n,int x)
{
    int left = 1;
    int right = n;
    int mid=-1;
    int ans=-1;
    while(left<=right)
    {
        mid = (left+right)/2;
        int value = modPow(mid,x);
        if(value<=n) ans=mid;
        if(value>n)
            right = mid-1;
        else if(value<n)
            left=mid+1;
        else
            return mid;
    }
    return ans;
}

int numberOfWays(int n, int x)
{
    int end = maxPower(n,x);
    vector<vector<int>> dp(end+1,vector<int>(n+1,0));
    for(int i=0;i<dp.size();i++) dp[i][0]=1;
    for(int i=1;i<dp[0].size();i++) dp[0][i]=0;
    for(int i=1;i<dp.size();i++)
    {
        for(int j=1;j<dp[0].size();j++)
        {
            int target = j;
            dp[i][j]+=dp[i-1][j];
            target-=modPow(i,x);
            if(target>=0)
            {
                dp[i][j]%=mod;
                dp[i][j]+=dp[i-1][target];
                dp[i][j]%=mod;
            }
        }
    }
    return dp[end][n];
}
