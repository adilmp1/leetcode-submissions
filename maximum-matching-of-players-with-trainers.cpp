    int matchPlayersAndTrainers(vector<int>& a, vector<int>& b) 
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int l1=0;
        int l2=0;
        int ans=0;
        while(l1<a.size() and l2<b.size())
        {
            if(a[l1]<=b[l2])
            {
                ans++;
                l1++;
                l2++;
            }
            else if(a[l1]>b[l2])
            {
                l2++;
            }
        }
        return ans;
    }
