void performQuery(vector<vector<int>>& ans,int row1, int col1, int row2, int col2,int n)
{   
    int boundaryRow=-1, boundaryCol=-1;
    for(int i=row1;i<=row2;i++)
    {
        ans[i][col1]++;
        if(col2+1<n)
        {
            ans[i][col2+1]--;
        }
        else if(i+1<n)
        {
            ans[i+1][0]--;
        }
    }
    
}

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
{
    vector<vector<int>> ans(n,vector<int>(n,0));
    for(int i=0;i<queries.size();i++) performQuery(ans,queries[i][0],queries[i][1],queries[i][2],queries[i][3],n);
    int prefixSum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            prefixSum+=ans[i][j];
            ans[i][j]=prefixSum;
        }
    }
    return ans;
}
