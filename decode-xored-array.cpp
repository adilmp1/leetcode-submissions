    vector<int> decode(vector<int>& a, int first) 
    {
        a.insert(a.begin(),first);
        for(int i=1;i<a.size();i++)
        {
            a[i]^=a[i-1];
        }
        return a;
    }
