    bool containsDuplicate(vector<int>& a) 
    {
        unordered_map<int,int> mp;
        for(int i:a)
        {
            if(mp.find(i)!=mp.end()) return true;
            mp[i]++;
        }    
        return false;
    }
