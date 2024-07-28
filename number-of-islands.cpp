bool isValid(int row,int col,vector<vector<char>>& a)
{
    if(row<0 or row>=a.size()) return false;
    if(col<0 or col>=a[0].size()) return false;
    return true;
}
void dfs(int row,int col,vector<vector<char>>& a)
{
    if(!isValid(row,col,a)) return;
    a[row][col]='`';
    if(isValid(row+1,col,a) and a[row+1][col]=='1') dfs(row+1,col,a);
    if(isValid(row-1,col,a) and a[row-1][col]=='1') dfs(row-1,col,a);
    if(isValid(row,col+1,a) and a[row][col+1]=='1') dfs(row,col+1,a);
    if(isValid(row,col-1,a) and a[row][col-1]=='1') dfs(row,col-1,a);
}

int numIslands(vector<vector<char>> &a)
{
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(a[i][j]=='1')
            {
                count++;
                dfs(i,j,a);
            }
        }
    }
    return count;
}
