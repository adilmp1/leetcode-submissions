vector<int> X = {0,0,1,-1};
vector<int> Y = {1,-1,0,0};
bool isNotValid(int x,int y,int n)
{
    return (x<0 or y<0 or x>=n or y>=n);
}
int dfs(vector<vector<int>> &a,int x,int y,vector<vector<bool>>& visited,int idx,vector<vector<int>>& mp)
{
    int n = a.size();
    if(isNotValid(x,y,n)) return 0;
    if(visited[x][y]) return 0;
    visited[x][y]=true;
    int ans=a[x][y];
    if(!ans) return 0;
    mp[x][y]=idx;
    for(int i=0;i<4;i++)
    {
        ans+=dfs(a,x+X[i],y+Y[i],visited,idx,mp);
    }
    return ans;
}
int largestIsland(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> mp(n,vector<int>(n,-1)); 
    vector<int> value(n*n,0);
    vector<vector<bool>> visited(n,vector<bool>(n,false)); 
    int idx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j] and !visited[i][j])
            {
                int val = dfs(a,i,j,visited,idx,mp);
                value[idx]=val;
                idx++;  
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!a[i][j])
            {
                set<int> s;
                
                for(int k=0;k<4;k++)
                {
                    int x = i+X[k];
                    int y = j+Y[k];
                    if(isNotValid(x,y,n)) continue;
                    s.insert(mp[x][y]);
                }
                int size = 1;
                for(int st:s)
                {
                    if(st!=-1) 
                    {
                        size+=value[st];
                    }
                }
                ans = max(ans,size);
            }
        }
    }
    if(!ans) return n*n;
    return ans; 
}
