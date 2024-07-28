bool isValid(int row,int col,vector<vector<int>>& a)
{
    if(row<0 or row>=a.size()) return false;
    if(col<0 or col>=a[0].size()) return false;
    return true;
}
int bfs(int row,int col,vector<vector<int>>& a,int count,int err)
{
    if(isValid(row+1,col,a) and a[row+1][col]==1) 
    {
        count++;
        a[row+1][col]=err+1;
    }
    if(isValid(row-1,col,a) and a[row-1][col]==1) 
    {
        count++;
        a[row-1][col]=err+1;
        
    }
    if(isValid(row,col+1,a) and a[row][col+1]==1) 
    {
        count++;
        a[row][col+1]=err+1;
    }
    if(isValid(row,col-1,a) and a[row][col-1]==1) 
    {
        count++;
        a[row][col-1]=err+1;
    }
    return count;
}

int orangesRotting(vector<vector<int>> &a)
{
    int ans=0;
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(a[i][j]==1)
            {
                count++;
            }
        }
    }
    bool flag=true;
    int err=2;
    while(flag and count)
    {
        flag=false;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<a[0].size();j++)
            {
                if(a[i][j]==err)
                {
                    flag=true;
                    int done=bfs(i,j,a,0,err);
                    count-=done;
                }
            }
        }
        ans++;
        err++;
    }
    if(count==0) return ans;
    return -1;
}
