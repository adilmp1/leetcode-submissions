int maxAscendingSum(vector<int> &a)
{
    int ans=0;
    int n = a.size();
    for(int i=0;i<n;)
    {
        ans = max(ans,a[i]);
        int sum=0;
        while(i==n-1 or (i<n and a[i]<a[i+1]))
        {
            sum+=a[i];
            i++;
        }
        if(i<n-1) sum+=a[i];
        ans = max(ans,sum);
        i++;
    }
    return ans;
}
