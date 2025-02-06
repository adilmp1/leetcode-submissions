int nc2(int n)
{
    n*=(n-1);
    n/=2;
    return n;
}

int tupleSameProduct(vector<int> &a)
{
    unordered_map<int,int> mp;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            int product = a[i]*a[j];
            mp[product]++;
        }
    }
    int ans=0;
    for(auto & pair:mp)
    {
        if(pair.second>1)
        {
            int val = nc2(pair.second);
            val*=8;
            ans+=val;
        }
    }
    return ans;
}
