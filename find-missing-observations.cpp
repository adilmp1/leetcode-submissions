vector<int> missingRolls(vector<int> &a, int mean, int n)
{
    vector<int> ans;
    int total = mean*(n+a.size());
    int sum=0;
    for(auto i:a) sum+=i;
    int pending = total-sum;
    int least = pending/n;
    if(pending>6*n) return ans;
    if(least>6) return ans;
    if(least<=0) return ans;
    for(int i=0;i<n;i++) ans.push_back(least);
    int val = pending-n*least;
    int idx=0;
    while(val--)
    {
        ans[idx]++;
        idx++;
    }
    return ans;
}
