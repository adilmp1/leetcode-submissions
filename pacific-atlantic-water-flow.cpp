// First Solution - Complex
bool isValid(int row, int col, vector<vector<int>> &a)
{
    if (row < 0 or row >= a.size())
        return false;
    if (col < 0 or col >= a[0].size())
        return false;
    return true;
}
bool isPacific(int row, int col, vector<vector<int>> &a)
{
    if (row <= 0 or col <= 0)
        return true;
    return false;
}
bool isAtlantic(int row, int col, vector<vector<int>> &a)
{
    if (row >= a.size() - 1 or col >= a[0].size() - 1)
        return true;
    return false;
}

bool pacific=false;
bool atlantic=false;

bool dfs(int row, int col, vector<vector<int>> &a,int prev)
{
    if(isAtlantic(row,col,a)) return true;
    int curr=prev;
    bool b1=false;
    bool b2=false;
    bool b3=false;
    bool b4=false;
    if(isValid(row+1,col,a) and a[row+1][col]!=-1 and a[row+1][col]<=curr) 
    {
        int temp=a[row+1][col];
        a[row+1][col]=-1;
        b1=dfs(row+1,col,a,temp);
        a[row+1][col]=temp;
    }
    if(b1) return true;
    if(isValid(row-1,col,a) and a[row-1][col]!=-1 and a[row-1][col]<=curr) 
    {
        int temp=a[row-1][col];
        a[row-1][col]=-1;
        b2=dfs(row-1,col,a,temp);
        a[row-1][col]=temp;
    }
    if(b2) return true;
    if(isValid(row,col+1,a) and a[row][col+1]!=-1 and a[row][col+1]<=curr) 
    {
        int temp=a[row][col+1];
        a[row][col+1]=-1;
        b3=dfs(row,col+1,a,temp);
        a[row][col+1]=temp;
    }
    if(b3) return true;
    if(isValid(row,col-1,a) and a[row][col-1]!=-1 and a[row][col-1]<=curr) 
    {
        int temp=a[row][col-1];
        a[row][col-1]=-1;
        b4=dfs(row,col-1,a,temp);
        a[row][col-1]=temp;
    }
    if(b4) return true;
    return false;
}
bool dfs2(int row, int col, vector<vector<int>> &a,int prev)
{
    if(isPacific(row,col,a)) return true;
    int curr=prev;
    bool b1=false;
    bool b2=false;
    bool b3=false;
    bool b4=false;
    if(isValid(row+1,col,a) and a[row+1][col]!=-1 and a[row+1][col]<=curr) 
    {
        int temp=a[row+1][col];
        a[row+1][col]=-1;
        b1=dfs2(row+1,col,a,temp);
        a[row+1][col]=temp;
    }
    if(b1) return true;
    if(isValid(row-1,col,a) and a[row-1][col]!=-1 and a[row-1][col]<=curr) 
    {
        int temp=a[row-1][col];
        a[row-1][col]=-1;
        b2=dfs2(row-1,col,a,temp);
        a[row-1][col]=temp;
    }
    if(b2) return true;
    if(isValid(row,col+1,a) and a[row][col+1]!=-1 and a[row][col+1]<=curr) 
    {
        int temp=a[row][col+1];
        a[row][col+1]=-1;
        b3=dfs2(row,col+1,a,temp);
        a[row][col+1]=temp;
    }
    if(b3) return true;
    if(isValid(row,col-1,a) and a[row][col-1]!=-1 and a[row][col-1]<=curr) 
    {
        int temp=a[row][col-1];
        a[row][col-1]=-1;
        b4=dfs2(row,col-1,a,temp);
        a[row][col-1]=temp;
    }
    if(b4) return true;
    return false;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &a)
{
    vector<vector<int>> ans;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            pacific=false;
            atlantic=false;
            if(dfs(i,j,a,a[i][j]) and dfs2(i,j,a,a[i][j]))
            {
                ans.push_back({i,j});
            }
        }
    }
    return ans;
}
