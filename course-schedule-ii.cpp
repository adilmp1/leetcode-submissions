vector<int> findOrder(int numCourses, vector<vector<int>> &a)
{
    unordered_map<int,vector<int>> mp;
    unordered_map<int,bool> dp;
    vector<int> ans;
    vector<int> indegree(numCourses,0);
    for(auto i:a)
    {
        mp[i[1]].push_back(i[0]);
        indegree[i[0]]++;
    }
    int completed=0;
    queue<int> q;
    for(int i=0;i<numCourses;i++)
    {
        if(!indegree[i])
        {
            q.push(i);
            dp[i]=true;
        }
    }
    while(!q.empty())
    {
        int idx=q.front();q.pop();
        ans.push_back(idx);
        for(auto i:a)
        {
            if(i[1]==idx)
            {
                indegree[i[0]]--;
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!indegree[i] and !dp[i])
            {
                dp[i]=true;
                q.push(i);
            }
        }
    }
    if(ans.size()!=numCourses) return {};
    return ans;
}
