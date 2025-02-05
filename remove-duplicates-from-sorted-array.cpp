    int removeDuplicates(vector<int>& a) 
    {
        int idx=0;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 and a[i]==a[i-1]) continue;
            a[idx++] = a[i];
        }
        return idx;
    }
