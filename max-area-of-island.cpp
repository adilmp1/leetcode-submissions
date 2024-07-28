bool isValid(int row,int col,vector<vector<int>>& a)
{
    if(row<0 or row>=a.size()) return false;
    if(col<0 or col>=a[0].size()) return false;
    return true;
}
int dfs(int row,int col,vector<vector<int>>& a)
{
    if(!isValid(row,col,a)) return 0;
    a[row][col]=0;
    int ans=0;
    if(isValid(row+1,col,a) and a[row+1][col]==1) 
    {
        ans++;
        ans+=dfs(row+1,col,a);
    }
    if(isValid(row-1,col,a) and a[row-1][col]==1) 
    {
        ans++;
        ans+=dfs(row-1,col,a);
    }
    if(isValid(row,col+1,a) and a[row][col+1]==1) 
    {
        ans++;
        ans+=dfs(row,col+1,a);
    }
    if(isValid(row,col-1,a) and a[row][col-1]==1) 
    {
        ans++;
        ans+=dfs(row,col-1,a);
    }
    return ans;
}

int maxAreaOfIsland(vector<vector<int>> &a)
{
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(a[i][j]==1)
            {
                ans = max(ans,1+dfs(i,j,a));
            }
        }
    }
    return ans;
}
