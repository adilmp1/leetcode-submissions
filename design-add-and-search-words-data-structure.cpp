    unordered_map<string,int> mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        if(!mp.count(word)) mp[word]=1;
    }
    
    bool search(string s) {
        int dots=0;
        int x = -1;
        int y = -1;
        for(int i=0;i<s.size();i++) 
        {
            char ch = s[i];
            if(ch=='.' and x!=-1) y=i;
            else if(ch=='.') x=i; 
            dots+=(ch=='.');
        }
        if(!dots) return mp.count(s);
        if(dots==1)
        {
            string temp = s;
            for(char ch='a';ch<='z';ch++)
            {
                temp[x]=ch;
                if(mp.count(temp)) return true;    
            }
            return false;
        }
        
        if(dots==2)
        {
            string temp = s;
            for(char ch1='a';ch1<='z';ch1++)
            {
                for(char ch2='a';ch2<='z';ch2++)
                {
                    temp[x]=ch1;
                    temp[y]=ch2;
                    if(mp.count(temp)) return true;    
                }
            }
        }
        return false;

    }
