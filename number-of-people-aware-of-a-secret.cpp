// bottom up dp, tabulation

const int mod = 1e9+7;
int peopleAwareOfSecret(int n, int delay, int forget)
{
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    int count=0;
    for(int i=2;i<=n;i++)
    {
        if(i-delay>0) count = (count+dp[i-delay])%mod;
        if(i-forget>0) count = (count-dp[i-forget]+mod)%mod;
        dp[i]=count%mod;     
    }
    int ans=0;
    for(int i=n-forget+1;i<=n;i++) ans = (ans+dp[i])%mod;
    return ans;
}

// recursion + memoization 

const int mod = 1e9+7;

int helper(int n, int delay, int forget,int value,vector<int>& dp,int day=1)
{
    if(day>n) return 0;
    if(dp[day]!=-1) return dp[day];
    int ans=0;
    if(day>value) ans=1;
    for(int i=delay;i<forget;i++)
    {
        ans%=mod;
        ans+=helper(n,delay,forget,value,dp,day+i);
        ans%=mod;
    }
    return dp[day]=ans;
}

int peopleAwareOfSecret(int n, int delay, int forget,int day=1)
{
    vector<int> dp(n+1,-1);
    return helper(n,delay,forget,n-forget,dp);
}
