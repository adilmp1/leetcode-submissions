int distance2(int x1,int y1,int x2, int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int lower_bound(vector<vector<int>> &points,int x_centre,int radius)
{
    int low = 0;
    int high = points.size()-1;
    int ans=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        int x = points[mid][0];
        
        if(x_centre-x<=radius)
        {
            high = mid-1;
            ans = mid;
        }
        else 
        {
            low=mid+1;
        }
    }
    return ans;
}

vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries)
{
    sort(points.begin(),points.end());
    vector<int> ans;
    for(auto query:queries)
    {
        int xc = query[0];
        int yc = query[1];
        int radius = query[2];
        int radius2 = radius*radius;
        int idx = lower_bound(points,xc,radius);
        int cnt=0;
        for(int i=idx;i<points.size();i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            if(x-xc>radius) break;
            
            if(distance2(x,y,xc,yc)<=radius2) cnt++;
        }
        ans.push_back(cnt);
    }
    return ans;
}
