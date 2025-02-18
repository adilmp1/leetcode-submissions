    vector<int> getRow(int n) 
    {
        if(n==0) return {1};
        if(n==1) return {1,1};
        vector<int> a = {1,1};
        for(int size=2;size<=n+1;size++)
        {
            vector<int> temp = a;
            vector<int> v;
            for(int i=0;i<size;i++)
            {
                if(i==0 or i==size-1) v.push_back(1);
                else v.push_back(temp[i]+temp[i-1]); 
            }
            a = v;
            if(size==n+1) return a;
        }
        return {};    
    }
