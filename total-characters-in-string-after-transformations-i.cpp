int lengthAfterTransformations(string s, int t)
{
    int ans=0;
    vector<int> map(26,0);
    for(char ch:s)
    {
        map[ch-97]++;
    }
    int mod = 1e9+7;
    for(int i=1;i<=t;i++)
    {
        int val = map[25];
        for(int i=25;i>=1;i--)
        {
            map[i]=map[i-1];
            map[i-1]=0; 
        }
        map[0]+= val;
        map[0]%=mod;
        map[1]+= val;
        map[1]%=mod;
    }
    for(int i:map) 
    {
        ans+=i;
        ans%=mod;
    }
    return ans;
}
