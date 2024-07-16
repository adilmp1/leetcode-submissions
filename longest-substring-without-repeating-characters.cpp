    int lengthOfLongestSubstring(string s) 
    {
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<int,int> mp;
        while(right<s.size())
        {
            if(mp.find(s[right])==mp.end() or (mp.find(s[right])!=mp.end() and mp[s[right]]==0))
            {
                mp[s[right]]=1;
                right++;
                ans=max(ans,right-left);
            }
            else
            {
                while(left<s.size() and mp[s[right]]!=0)
                {
                    mp[s[left]]--;
                    left++;
                }
            }
        }
        return ans;
    }
