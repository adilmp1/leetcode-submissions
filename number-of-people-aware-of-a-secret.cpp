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
