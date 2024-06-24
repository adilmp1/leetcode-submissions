int jump(vector<int>& a)
{
    int n = a.size();
    int l=0,r=0,maxReachable=0,ans=0;
    while(r<n-1)
    {   
        for(int i=l;i<=r;i++)
        {
            maxReachable = max(maxReachable,i+a[i]);
        }
        l=r+1;
        r=maxReachable;
        ans++;
    }
    return ans;
}
