    void nextPermutation(vector<int>& a) 
    {
        int n=a.size();
        int idx=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                idx=i;
                break;
            }
        }
        int idx2=-1;
        int value = INT_MAX;
        for(int i=idx+1;idx!=-1 and i<n;i++)
        {
            if(a[i]>a[idx])
            {
                if(value>=a[i])
                {
                    value=a[i];
                    idx2=i;
                }
            }
        }
        if(idx!=-1) swap(a[idx],a[idx2]);
        reverse(a.begin()+idx+1,a.end());
    }
