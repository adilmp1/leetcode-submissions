    int removeDuplicates(vector<int>& a) 
    {
        int idx=0;
        for(int x:a) if(idx==0 or idx==1 or a[idx-2]!=x) a[idx++]=x;
        return idx;
    }
