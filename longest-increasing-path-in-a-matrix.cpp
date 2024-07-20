bool isValid(int i,int j,int m,int n)
{
    return !(i<0 or i>=m or j<0 or j>=n);
}
int longestIncreasingPathHelper(vector<vector<int>> &a,int m,int n,int i,int j,vector<vector<int>>& dp)
{
    if(i<0 or i>=m or j<0 or j>=n) return 0;
    int v1=0,v2=0,v3=0,v4=0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(isValid(i+1,j,m,n) and a[i+1][j]>a[i][j])
        v1 = 1+longestIncreasingPathHelper(a,m,n,i+1,j,dp);
    if(isValid(i-1,j,m,n) and a[i-1][j]>a[i][j])
        v2 = 1+longestIncreasingPathHelper(a,m,n,i-1,j,dp);
    if(isValid(i,j+1,m,n) and a[i][j+1]>a[i][j])
        v3 = 1+longestIncreasingPathHelper(a,m,n,i,j+1,dp);
    if(isValid(i,j-1,m,n) and a[i][j-1]>a[i][j])
        v4 = 1+longestIncreasingPathHelper(a,m,n,i,j-1,dp);

    return dp[i][j]=max({v1,v2,v3,v4});
}
int longestIncreasingPath(vector<vector<int>> &a)
{
    int m = a.size();
    int n = a[0].size();
    int ans=INT_MIN;
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans=max(ans,longestIncreasingPathHelper(a,m,n,i,j,dp));
        }
    }
    return ans+1;
}
