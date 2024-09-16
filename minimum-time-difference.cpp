int getTimeInMinutes(string s)
{
    int v1 = stoi(s.substr(0,2));
    int v2 = stoi(s.substr(3,2));
    int diff = 60*v1+v2;
    return diff;
}

int findMinDifference(vector<string> &a)
{
    int n = a.size();
    vector<int> minutes(n);
    for(int i=0;i<n;i++)
    {
        minutes[i]=getTimeInMinutes(a[i]);
    }
    sort(minutes.begin(),minutes.end());
    int ans=INT_MAX;
    for(int i=1;i<n;i++)
    {
        ans=min(ans,minutes[i]-minutes[i-1]);
    }
    return min(ans, (24*60 - minutes[n-1] + minutes[0]));
}
