int maxRemoval(vector<int> &a, vector<vector<int>> &queries)
{
    int n = a.size();
    sort(queries.begin(),queries.end());
    int applied=0,idx=0;

    priority_queue<int> available;
    priority_queue<int,vector<int>,greater<int>> used;

    for(int i=0;i<n;i++)
    {
        while(idx<queries.size() and queries[idx][0]==i)
        {
            available.push(queries[idx][1]);
            idx++;
        }

        a[i]-=used.size();

        while(a[i]>0 and !available.empty() and available.top()>=i)
        {
            applied++;
            a[i]--;
            used.push(available.top());
            available.pop();
        }

        if(a[i]>0) return -1;

        while(!used.empty() and used.top()==i)
        {
            used.pop();
        }
    }
    return queries.size()-applied;  
}
