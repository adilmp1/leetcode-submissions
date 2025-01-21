#define ll long long 
ll gridGame(vector<vector<int>> &a)
{
    int n = a[0].size();
    ll top_sum = accumulate(a[0].begin(),a[0].end(),0LL);
    top_sum-=a[0][0];
    ll bottom_sum = 0;
    ll ans = LONG_MAX;
    for(int i=1;i<n;i++)
    {
        ans = min(ans,max(top_sum,bottom_sum));
        top_sum-=a[0][i];
        bottom_sum+=a[1][i-1];
    }
    ans = min(ans,max(top_sum,bottom_sum));
    return ans;
}
