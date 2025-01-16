int uniquePathsWithObstacles(vector<vector<int>> &a)
{
    int m = a.size();
    int n = a[0].size();
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    
    for(int i=0;i<n;i++)
    {
        if(a[0][i]) break;
        dp[0][i]=1;
    }
    for(int i=0;i<m;i++)
    {
        if(a[i][0]) break;
        dp[i][0]=1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(!a[i][j])
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}
