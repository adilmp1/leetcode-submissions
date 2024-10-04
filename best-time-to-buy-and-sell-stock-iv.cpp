int helper(vector<int>&a,int idx,int canBuy,int transactions,vector<vector<vector<int>>>& dp,int k)
{
    if(idx>=a.size() or transactions>=k) return 0;
    if(dp[idx][canBuy][transactions]!=-1) return dp[idx][canBuy][transactions];
    int sum=0;
    if(canBuy)
    {
        int buy = -a[idx]+helper(a,idx+1,false,transactions,dp,k);
        int skip = helper(a,idx+1,true,transactions,dp,k);
        sum = max(buy,skip);
    }
    else
    {
        int sell = a[idx]+helper(a,idx+1,true,transactions+1,dp,k);
        int skip = helper(a,idx+1,false,transactions,dp,k);
        sum = max(sell,skip);
    }
    return dp[idx][canBuy][transactions]=sum;
}

int maxProfit(int k,vector<int> &a)
{
    int n = a.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1))); 
    return helper(a,0,true,0,dp,k);
}
