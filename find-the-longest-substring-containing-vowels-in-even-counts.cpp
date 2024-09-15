    bool isVowel(char c)
    {
        return (c=='a') or (c=='e') or (c=='i') or (c=='o') or (c=='u');
    }
    int findTheLongestSubstring(string s) 
    {
        unordered_map<int,int> mp;
        int mask=0,ans=0;
        mp[0]=-1;
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                int val = (int) s[i]-'a';
                mask^=(1<<val);
            }

            if(mp.count(mask))
            {
                ans=max(ans,i-mp[mask]);
            }
            else
            {
                mp[mask]=i;
            }
        }   
        return ans; 
    }
