int maxChunksToSorted(vector<int> &a)
{
    int ans=0;
    int n = a.size();
    int target=0;
    int start=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]=1;
        target = max(target,a[i]);
        if(i==target)
        {
            bool flag=true;
            for(int j=start;j<=i;j++)
            {
                if(!mp.count(j))
                {
                    flag=false;
                }
            }
            if(flag)
            {
                ans++;
                start=i+1;
                target=i+1;
                continue;

            }
            else
            {
                return ans+1;
            }
        }
    }
    return ans;
}
