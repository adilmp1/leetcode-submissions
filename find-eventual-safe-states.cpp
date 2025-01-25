vector<int> eventualSafeNodes(vector<vector<int>> &a)
{
    int n = a.size();
    vector<int> indegree(n, 0);

    vector<vector<int>> reversedGraph(n);

    for (int i = 0; i < n; i++)
    {
        indegree[i] = a[i].size();
        for(auto v:a[i])
        {
            reversedGraph[v].push_back(i);
        }
    }

    vector<bool> visited(n, false);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (!indegree[i])
        {
            visited[i] = true;
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int idx = q.front();
        q.pop();
        ans.push_back(idx);
        
        for(auto node:reversedGraph[idx])
        {
            indegree[node]--;
            if(!indegree[node])
            {
                q.push(node);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
