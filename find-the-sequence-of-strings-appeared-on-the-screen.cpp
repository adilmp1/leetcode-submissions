    vector<string> stringSequence(string target) 
    {
        int n = target.size();
        vector<string> ans;
        string s(n,'`');
        int len = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<26;j++)
            {
                char ch = (char) (97+j);
                s[i-1]=ch;
                ans.push_back(s.substr(0,i));
                if(s[i-1]==target[i-1])
                {
                    break;
                }
            }
        }
        return ans;
    }
