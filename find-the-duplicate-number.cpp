    int findDuplicate(vector<int>& a) 
    {
        int idx=0;
        while(true)
        {
            a[idx]=-a[idx];
            cout<<"idx = "<<idx<<endl;
            cout<<a[idx]<<endl;
            if(a[idx]>0) return idx;
            idx=-a[idx];
        }    
    }
