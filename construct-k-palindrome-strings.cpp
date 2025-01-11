    bool canConstruct(string s, int k) 
    {
        if(s.size()==k) return true;
        if(s.size()<k) return false;
        vector<int> map(26,0);
        for(auto c:s) map[c-'a']++;
        int count=0;
        for(auto i:map) count+=(i%2);
        return (count<=k); 
    }
