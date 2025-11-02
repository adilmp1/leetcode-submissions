    int numberOfBeams(vector<string>& bank) {
        int prev=-1;
        int ans=0;
        for(string row:bank)
        {
            int count=0;
            for(char device:row)
            {
                count+=(device=='1');
            }
            if(prev==-1 and count)
            {
                prev=count;
            }
            else if(count)
            {
                ans+=(prev*count);
                prev=count;
            }
        }
        return ans;
    }
