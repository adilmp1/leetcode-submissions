    int longestPalindrome(vector<string>& a) 
    {
        unordered_map<string,int> mp;
        unordered_map<string,int> visited;
        for(string s:a) mp[s]++;
        
        int ans=0;
        int value = 0;

        for(string s:a)
        {
            string t = s;
            reverse(s.begin(),s.end());
            if(visited.find(t)==visited.end())
            {
                if(s==t)
                {
                    int count = mp[s];
                    if((count%2)==0) 
                    {
                        ans+=(count*2);
                    }
                    else 
                    {
                        value = 2;
                        ans+=((count-1)*2);
                    }

                }
                else
                {
                    if(mp.count(s))
                    {
                        int val = min(mp[s],mp[t]);
                        val*=2;
                        ans+=val;
                    }
                }
                visited[t]=1;
            }
        }
        ans+=value;
        return ans;
    }  
