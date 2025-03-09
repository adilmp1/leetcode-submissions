int numberOfAlternatingGroups(vector<int>& a, int k) 
{
    for(int i=0;i<k-1;i++) a.push_back(a[i]);

    int count=1;
    int ans=0;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]!=a[i-1])
        {
            count++;
        }
        else
        {
            if(count>=k) ans+=(count-k)+1;
            count=1;
        }
    }
    if(count>=k) ans+=(count-k)+1;
    return ans;
}
