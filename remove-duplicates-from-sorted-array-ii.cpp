    int removeDuplicates(vector<int>& a) 
    {
        int n = a.size();
        for(int i=0;i<n-2;i++)
        {
            if(a[i]==a[i+1] and a[i]==a[i+2])
            {
                a[i]=INT_MAX;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==INT_MAX)
            {
                a.erase(a.begin()+i);
                i--;
            }
        }
        return a.size();
    }
