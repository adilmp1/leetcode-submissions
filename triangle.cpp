int helper(int row,int start,vector<vector<int>>& a,vector<vector<int>>& dp)
{
    if(row==a.size()) return 0;
    int ans = INT_MAX;

    if(dp[row][start]!=-1) return dp[row][start];

    ans = min(ans,a[row][start]+helper(row+1,start,a,dp));
    ans = min(ans,a[row][start]+helper(row+1,start+1,a,dp));
    return dp[row][start]=ans;
}

int minimumTotal(vector<vector<int>>& a)
{
    int n = a.size();
    int c = a[n-1].size();
    vector<vector<int>> dp(n+1,vector<int>(c+1,-1));
    return helper(0,0,a,dp);
}
