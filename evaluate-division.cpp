void dfs(unordered_map<string,unordered_map<string,double>> graph,string node,string& dest,unordered_map<string,int>& visited,double & ans,double temp)
{
    if(visited.count(node)) return;
    visited[node]=1;

    if(node==dest)
    {
        ans = temp;
        return;
    }

    for(auto & child:graph[node])
    {
        dfs(graph,child.first,dest,visited,ans,temp*child.second);
    }

}

unordered_map<string,unordered_map<string,double>> buildGraph(vector<vector<string>>& equations, vector<double>& values)
{
    unordered_map<string,unordered_map<string,double>> graph;
    for(int i=0;i<equations.size();i++)
    {
        string dividend = equations[i][0];
        string divisor = equations[i][1];

        double value = values[i];

        graph[dividend][divisor] = value;
        graph[divisor][dividend] = 1.0/value;
    }

    return graph;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
    unordered_map<string,unordered_map<string,double>> graph;
    vector<double> answer;
    graph = buildGraph(equations,values);

    for(int i=0;i<queries.size();i++)
    {
        string dividend = queries[i][0];
        string divisor = queries[i][1];

        if(graph.find(dividend)==graph.end() or graph.find(divisor)==graph.end())
        {
            answer.push_back(-1.0);
        }
        else
        {
            unordered_map<string,int> visited;
            double ans = -1.0;
            double temp = 1.0;
            dfs(graph,dividend,divisor,visited,ans,temp);
            answer.push_back(ans);
        }
    }
    return answer;
}
