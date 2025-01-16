// bottom up dp

int minimumTotal(vector<vector<int>>& a)
{
    int n = a.size();
    vector<int> dp(n,0);
    for(int i=0;i<n;i++)
    {
        dp[i]=a[n-1][i];
    }
    
    for(int i=n-2;i>=0;i--)
    {
        vector<int> temp(n,0);
        for(int j=i;j>=0;j--)
        {
            temp[j] = min(a[i][j]+dp[j],a[i][j]+dp[j+1]);
        }
        dp=temp;
    }
    return dp[0];
}



// recursion + memoization 
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
