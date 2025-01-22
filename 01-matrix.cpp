#define pip pair<int,pair<int, int>>

bool isValid(int x,int y,int m,int n)
{
    return (x>=0 and y>=0 and x<m and y<n);
}

vector<vector<int>> updateMatrix(vector<vector<int>> &a)
{
    priority_queue<pip, vector<pip>, greater<pip>> pq;
    int m = a.size();
    int n = a[0].size();
    vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!a[i][j])
            {
                ans[i][j]=0;
                pq.push({0,{i,j}});
            }
        }
    }
    vector<int> X = {0,0,1,-1};
    vector<int> Y = {1,-1,0,0};
    while(!pq.empty())
    {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(visited[x][y]) continue;;
        visited[x][y]=true;
        cout<<x<<" "<<y<<endl;  
        for(int i=0;i<4;i++)
        {
            int row = x+X[i];
            int col = y+Y[i];
            if(isValid(row,col,m,n))
            {
                int cost = ans[x][y]+1;
                if(cost<ans[row][col])
                {
                    ans[row][col] = cost;
                    pq.push({cost,{row,col}});
                }
            }
        }
    }
    return ans;
}
