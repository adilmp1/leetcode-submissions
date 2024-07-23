    vector<int> plusOneHelper(vector<int>& a,int last)
    {
        if(last<0)
        {
            a.insert(a.begin(),1);
            return a;
        }
        if(a[last]!=9)
        {
            a[last]++;
            return a;
        }
        a[last]=0;
        return plusOneHelper(a,last-1);
    }
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();
        return plusOneHelper(digits,n-1);
    }
