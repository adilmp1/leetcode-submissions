struct node {
    int time;
    pair<int, int> value;

    node(int k, pair<int, int> v) : time(k), value(v) {}
};

struct compare {
    bool operator()(const node& a, const node& b) {
        return a.time > b.time; 
    }
};

int minTimeToReach(vector<vector<int>>& a) 
{
    vector<int> X = {0,0,-1,1};
    vector<int> Y = {-1,1,0,0};
    int m = a.size();
    int n = a[0].size();
    priority_queue<node,vector<node>,compare> pq;
    pq.push({0,{0,0}});
    vector<vector<bool>> visited(m,vector<bool>(n,false));
    visited[0][0]=true;
    while(!pq.empty())
    {
        node curr = pq.top();
        pq.pop();
        int x = curr.value.first;
        int y = curr.value.second;
        if(x==m-1 and y==n-1) return curr.time;
        for(int i=0;i<4;i++)
        {
            int newX = x+X[i];
            int newY = y+Y[i];
            if(newX>=0 and newX<m and newY>=0 and newY<n and !visited[newX][newY]) 
            {
                pq.push({1+max(curr.time,a[newX][newY]),{newX,newY}});
                visited[newX][newY]=true;
            }
        }
    }
    return -1;
}
