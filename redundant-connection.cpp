int find(int node,vector<int> parent)
{
    while(parent[node]!=node)
    {
        node=parent[node];
    }
    return node;
}

void Union(int i,int j,vector<int>& parent)
{
    int x = find(i,parent);
    int y = find(j,parent);
    if(x!=y)
    {
        parent[y]=x;
    }
}

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++) parent[i]=i;
    for(auto &a:edges)
    {
        if(find(a[0],parent)==find(a[1],parent)) return a;
        Union(a[0],a[1],parent);
    }
    return {-1,-1};
}
