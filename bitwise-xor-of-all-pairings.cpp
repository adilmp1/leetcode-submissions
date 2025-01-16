    int xorArray(vector<int>& a)
    {
        int ans=0;
        for(int i:a)
        {
            ans^=i;
        }
        return ans;
    }

    int xorAllNums(vector<int>& a, vector<int>& b) 
    {
        bool f1 = a.size()%2==0;
        bool f2 = b.size()%2==0;

        if(f1 and f2)
        {
            return 0;
        }
        else if(f1 and !f2)
        {
            return xorArray(a);
        }
        else if(f2 and !f1)
        {
            return xorArray(b);
        }
        else
        {
            return xorArray(a)^xorArray(b);
        }
    }
