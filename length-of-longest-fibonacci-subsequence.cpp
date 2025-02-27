unordered_map<int,int> mp;
int helper(int v1,int v2)
{
    if(mp.find(v1+v2)==mp.end())
    {
        return 2;
    }
    return 1+helper(v2,v1+v2);
}
int lenLongestFibSubseq(vector<int>& a)
{
    for(int i:a) mp[i]=1;
    int n = a.size();
    int ans=2;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ans=max(ans,helper(a[i],a[j]));
        }
    }
    if(ans==2) return 0;
    return ans;
}
