int bits(int n)
{
    int ans=0;
    while(n)
    {
        ans+=(n%2);
        n/=2;
    }
    return ans;
}

vector<int> countBits(int n)
{
    vector<int> ans;
    for(int i=0;i<=n;i++)
    {
        ans.push_back(bits(i));
    }
    return ans;
}
