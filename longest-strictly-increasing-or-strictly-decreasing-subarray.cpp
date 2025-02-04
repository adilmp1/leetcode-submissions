int longestMonotonicSubarray(vector<int> &a)
{
    int n = a.size();
    int idx=0;
    int ans=0;
    int count=0;
    while(idx<n)
    {
        count=0;
        while((idx==n-1) or idx<n and a[idx]<a[idx+1])
        {
            count++;
            idx++;
        }
        if(idx<n-1) count++;
        ans = max(ans,count);
        if(idx<n-1 and a[idx]==a[idx+1]) 
        {
            idx++;
            continue;
        }
        count=0;
        while((idx==n-1) or idx<n and a[idx]>a[idx+1])
        {
            count++;
            idx++;
        }
        if(idx<n-1) count++;
        ans = max(ans,count);
        if(idx<n-1 and a[idx]==a[idx+1]) 
        {
            idx++;
            continue;
        }
    }
    return ans;
}
