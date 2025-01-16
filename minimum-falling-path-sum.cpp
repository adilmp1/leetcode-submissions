int helper(vector<vector<int>> &a,int row,int col)
{
    if(row<0 or col<0 or row>=a.size() or col>=a.size()) return INT_MAX;
    return a[row][col];
}

int minFallingPathSum(vector<vector<int>> &a)
{
    int n = a.size();
    if(n==1) return a[0][0];
    int mini;
    for(int i=1;i<n;i++)
    {
        mini = INT_MAX;
        for(int j=0;j<n;j++)
        {
            int v1 = helper(a,i-1,j);
            int v2 = helper(a,i-1,j-1);
            int v3 = helper(a,i-1,j+1);
            a[i][j]+=min({v1,v2,v3});
            mini = min(a[i][j],mini);
        }
    }

    return mini;
}
