int minPathSum(vector<vector<int>> &a)
{
    int m = a.size();
    int n = a[0].size();
    for(int i=1;i<n;i++)
    {
        a[0][i]+=a[0][i-1];
    }
    for(int i=1;i<m;i++)
    {
        a[i][0]+=a[i-1][0];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            a[i][j]+=min(a[i-1][j],a[i][j-1]);
        }
    }
    return a[m-1][n-1];
}
