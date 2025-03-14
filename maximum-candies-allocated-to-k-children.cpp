int binary_search(vector<int>& a, int k,bool flag_left=true)
{
    int left = 0;
    int right = a.size() - 1;
    int m;
    int ans=-1;
    while (left <= right)
    {
        m = (left + right) / 2;
        if (a[m]>=k)
        {
            ans = m;
            if(flag_left) right=m-1;
            else left = m+1;
        }
        else if (a[m] > k)
        {
            right = m - 1;
        }
        else
        {
            left = m + 1;
        }
    }
    return ans;
}


int maximumCandies(vector<int>& a, long long k) 
{
    sort(a.begin(),a.end());
    int left = 1;
    int right = a.back();
    int m;
    int ans = 0;
    while (left <= right)
    {
        m = (left + right) / 2;
        int start = binary_search(a,m);
        if (start!=-1)
        {
            int end = binary_search(a,m,false);
            long long val=0;
            for(int i=start;i<=end;i++)
            {
                val+=(a[i]/m);
            }
            if(val>=k) 
            {
                ans = max(ans,m);
                left = m+1;
            }
            else
            {
                right = m-1;
            }
        }
        else
        {
            right = m - 1;
        }
    }
    return ans;
}
