    int longestConsecutive(vector<int>& a) 
    {
        unordered_map<int,int> mp;
        for(int i:a)
        {
            mp[i]=1;
        }
        int ans=0;
        for(int i:a)
        {
            int val=i;
            if(mp[val]==2) continue;
            mp[val]=2;
            int length=1;
            while(mp.find(val+1)!=mp.end() and mp[val+1]!=2)
            {
                mp[val+1]=2;
                val++;
                length++;
            }
            val=i;
            while(mp.find(val-1)!=mp.end() and mp[val-1]!=2)
            {
                mp[val-1]=2;
                val--;
                length++;
            }
            ans=max(ans,length);
        }
        return ans;
    }
