int helper(vector<int>&a,int idx,int canBuy,vector<vector<int>>& dp)
{
    if(idx>=a.size()) return 0;
    if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
    int sum=0;
    if(canBuy)
    {
        int buy = -a[idx]+helper(a,idx+1,false,dp);
        int skip = helper(a,idx+1,true,dp);
        sum = max(buy,skip);
    }
    else
    {
        int sell = a[idx]+helper(a,idx+1,true,dp);
        int skip = helper(a,idx+1,false,dp);
        sum = max(sell,skip);
    }
    return dp[idx][canBuy]=sum;
}

int maxProfit(vector<int> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n,vector<int>(2,-1)); 
    return helper(a,0,true,dp);
}
