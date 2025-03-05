    string stringHash(string s, int k) 
    {
        int n = s.size();
        string ans = "";
        int count=0;
        int sum=0;
        for(auto c:s)
        {
            if(count==k)
            {
                ans+=(char)97+sum%26;
                sum=0;
                count=0;
            }
            count++;
            sum+=(int)c-'a';
        }
        ans+=(char)97+sum%26;
        return ans;
    }
