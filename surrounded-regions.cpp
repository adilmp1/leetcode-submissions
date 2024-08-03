bool isValid(vector<vector<char>> &a, int i, int j)
{
    if (i < 0 or i >= a.size())
        return false;
    if (j < 0 or j >= a[0].size())
        return false;
    return true;
}
void helper(vector<vector<char>> &a, int i, int j, vector<vector<bool>>& vis)
{
    if (!isValid(a, i, j) or a[i][j] != 'O' or vis[i][j])
        return;
    vis[i][j] = true;
    a[i][j] = '`';
    helper(a, i, j + 1, vis);
    helper(a, i, j - 1, vis);
    helper(a, i + 1, j, vis);
    helper(a, i - 1, j, vis);
}

void solve(vector<vector<char>> &a)
{
    int m = a.size();
    int n = a[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int j = 0; j < a[0].size(); j++)
    {
        if (a[0][j] == 'O')
        {
            helper(a,0,j,vis);
        }
    }
    for (int j = 0; j < a[0].size(); j++)
    {
        if (a[m-1][j] == 'O')
        {
            helper(a,m-1,j,vis);
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if (a[i][0] == 'O')
        {
            helper(a,i,0,vis);
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if (a[i][n-1] == 'O')
        {
            helper(a,i,n-1,vis);
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='O')
            {
                a[i][j]='X';
            }
            if(a[i][j]=='`')
            {
                a[i][j]='O';
            }
        }
    }
}
