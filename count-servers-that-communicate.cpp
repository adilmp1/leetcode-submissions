int countServers(vector<vector<int>> &a)
{
    int m = a.size();
    int n = a[0].size();

    vector<int> rowCount(m,0);
    vector<int> colCount(n,0);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j])
            {
                rowCount[i]++;
                colCount[j]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j])
            {
                ans+=(rowCount[i]>1 or colCount[j]>1);
            }
        }
    }
    return ans;
}
