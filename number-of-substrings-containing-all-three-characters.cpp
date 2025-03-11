    int numberOfSubstrings(string s) 
    {
        int left = 0;
        int right = 0;
        int n = s.size();
        unordered_map<int,int> mp;
        int ans=0;
        while(right<n)
        {
            char ch = s[right];
            mp[ch]++;
            if(mp.size()==3) ans+=n-right;

            while(mp.size()==3)
            {
                ch = s[left];
                left++;
                mp[ch]--;
                if(mp[ch]==0) mp.erase(ch);
                if(mp.size()==3) ans+=n-right;
            }
            right++;
        }    
        return ans;
    }
