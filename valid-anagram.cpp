    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char i:s) mp1[i]++;
        for(char i:t) mp2[i]++;
        if(mp1.size()!=mp2.size()) return false;
        for(auto & pair:mp1)
        {
            if(pair.second!=mp2[pair.first]) return false;
        }
        return true;
    }
