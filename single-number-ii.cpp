int singleNumber(vector<int>& a) 
{
    int ans=0;
    int idx=0;
    for(int i=0;i<32;i++)
    {
        int xr=0;
        for(int j=0;j<a.size();j++)
        {
            int val = a[j];
            xr += (val&(1<<i))!=0;
        }
        xr%=3;
        ans+=(xr*(1<<idx++));
    }
    int count=0;
    for(auto i:a) if(i==ans) count++; 
    if(count==0)
    {
        return -ans;
    }
    else 
    {
        if(count>2)
        {
            return -ans;
        }
        return ans;
    }
}
