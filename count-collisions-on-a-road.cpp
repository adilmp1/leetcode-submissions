    int countCollisions(string str) {
        vector<char> s;
        int ans=0;
        for(int i=0;i<str.size();i++)
        {
            char ch = str[i];
            if(ch=='R')
            {
                if(!s.empty() and s.back()!=ch) s.clear();
                s.push_back(ch);
            }
            else if(ch=='S')
            {
                while(!s.empty() and s.back()=='R') 
                {
                    s.pop_back();
                    ans++;
                }
                s.clear();
                s.push_back(ch);
            }
            else
            {
                if(!s.empty() and s.back()=='R') ans++;
                for(int j=i+1;j<str.size() and str[j]=='L' and !s.empty();j++) ans++;
                while(!s.empty())
                {
                    ans++;
                    s.pop_back();
                }
            }
        }
        return ans;
    }
