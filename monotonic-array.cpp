    bool isMonotonicIncreasing(vector<int>& a,int idx) 
    {
        for(int i=idx+1;i<a.size();i++)
        {
            if(a[i]<a[i-1])
            {
                return false;
            }
        }
        return true;
    }
    bool isMonotonicDecreasing(vector<int>& a,int idx) 
    {
        for(int i=idx+1;i<a.size();i++)
        {
            if(a[i]>a[i-1])
            {
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& a) 
    {
        int n = a.size();
        int i=1;
        while(i<n and a[i]==a[i-1]) i++;
        if(i>=n-1) return true;
        if(a[i]>a[i-1]) return isMonotonicIncreasing(a,i);
        return isMonotonicDecreasing(a,i);
    }
