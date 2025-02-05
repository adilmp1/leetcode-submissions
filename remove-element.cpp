    int removeElement(vector<int>& a, int val) 
    {
        int idx=0;
        int n = a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]==val) continue;
            a[idx++] = a[i];
        }
        return idx;    
    }
