struct CompareIntervals
{
    bool operator()(const vector<int> &a, const vector<int> &b) const
    {
        
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]<b[1];
    }
};

int intersectionSizeTwo(vector<vector<int>> &intervals)
{
    sort(intervals.begin(),intervals.end(),CompareIntervals());
    int a = intervals[0][1]-1;
    int b = intervals[0][1];
    int ans = 2;
    for(auto & interval:intervals)
    {
        if(interval[0] > b)
        {
            a = interval[1]-1;
            b = interval[1];
            ans+=2;
        }
        else if(interval[0]>a and interval[0]<=b)
        {
            ans++;
            a=b;
            b=interval[1];
        }
    }
    return ans;
}
