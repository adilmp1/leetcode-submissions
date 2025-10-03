bool canTalk(int fnd1,int fnd2,vector<unordered_set<int>>& knownLanguages)
{
    for(auto language:knownLanguages[fnd1])
    {
        if(knownLanguages[fnd2].count(language)) return true;
    }
    return false;
}

int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
{
    int ans=0;
    int m = languages.size();
    vector<unordered_set<int>> knownLanguages(m+1);
    vector<int> frequency(n+1,0);
    unordered_set<int> cantTalkFriends;
    vector<bool> seen(m+1,false);
    for(int i=0;i<m;i++)
    {
        auto & fndLanguages = languages[i];   
        for(auto & language:fndLanguages) knownLanguages[i+1].insert(language);
    }
    int maxFreq = 0;
    int maxKnownLanguage = -1;

    
    for(auto & friendship:friendships)
    {
        int fnd1 = friendship[0];
        int fnd2 = friendship[1];
        
        if(!canTalk(fnd1,fnd2,knownLanguages))
        {
            if(!seen[fnd1])
            {
                seen[fnd1]=true;
                for(auto & language:knownLanguages[fnd1]) frequency[language]++;
                cantTalkFriends.insert(fnd1);
            }
            if(!seen[fnd2]) 
            {
                seen[fnd2]=true;
                for(auto & language:knownLanguages[fnd2]) frequency[language]++;
                cantTalkFriends.insert(fnd2);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(frequency[i]>maxFreq)
        {
            maxFreq = frequency[i];
            maxKnownLanguage=i;
        }
    }

    for(int i:cantTalkFriends)
    {
        if(knownLanguages[i].find(maxKnownLanguage)==knownLanguages[i].end()) ans++;
    }
    
    return ans;
}
