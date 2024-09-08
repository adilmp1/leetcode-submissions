    vector<int> frequencySort(vector<int>& a) 
    {
        unordered_map<int,int> mp;
        for(auto i : a)    
        {
            mp[i]++;
        }
        sort(a.begin(), a.end(), [&](const int &a, const int &b) {
            if (mp[a] != mp[b])
                return mp[a] < mp[b];
            return a > b;
        });
        return a;
    }
