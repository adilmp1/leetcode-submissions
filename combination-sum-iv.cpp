int helper(vector<int>& a,int target,vector<int>& dp)
{
    if(target<0) return 0;
    if(target==0) return 1;
    if(dp[target]!=-1) return dp[target];
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        target-=a[i];
        ans+=helper(a,target,dp);
        target+=a[i];
    }
    return dp[target]=ans;
}
int combinationSum4(vector<int> &a, int target)
{
    vector<int> dp(target+1,-1);
    return helper(a,target,dp);
}
