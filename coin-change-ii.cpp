// DP solution
int change(int amount, vector<int>& a) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; 

    for (int coin : a) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}



// My solution memoization
int changeHelper(int target,vector<int>& a,int idx,vector<vector<int>>& dp)
{
    if(target==0) return 1;
    if(target<0) return 0;
    if(idx>=a.size()) return 0;
    if(dp[idx][target]!=-1) return dp[idx][target];
    int ans=0;
    for(int i=idx;i<a.size();i++)
    {
        ans+=changeHelper(target-a[i],a,i,dp);
    }
    
    return dp[idx][target]=ans;
}
int change(int amount, vector<int>& a)
{
    vector<vector<int>> dp(a.size(),vector<int>(amount+1,-1));
    return changeHelper(amount,a,0,dp);
}
