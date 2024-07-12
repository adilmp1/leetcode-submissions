    bool checkInclusion(string s1, string s2) 
    {
        int size=s1.size();
        int n=s2.size();
        if(n<size) return false;
        vector<int> mp(26,0);
        vector<int> mp2(26,0);
        for(char i:s1)
        {
            mp[i-97]++;
        }
        for(int i=0;i<size;i++)
        {
            mp2[s2[i]-97]++;
        }
        if(mp==mp2) return true;
        int left=0;
        for(int i=size;i<n;i++)
        {
            mp2[s2[i]-97]++;
            mp2[s2[left]-97]--;
            left++;
            if(mp==mp2) return true;
        }
        return false;
    }
