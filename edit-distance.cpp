int minDistance(string a, string b)
{
    int m = a.size();
    int n = b.size();
    
    // m columns and n rows
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=m;i++) dp[0][i]=i;
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[j-1]==b[i-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}
