vector<string> uncommonFromSentences(string s1, string s2)
{
    vector<string> ans;
    unordered_map<string,int> mp1;
    unordered_map<string,int> mp2;
    string s="";
    for(auto c:s1)
    {
        if(c==' ')
        {
            mp1[s]++;
            s.clear();
            continue;
        }
        s+=c;
    }
    if(s.back()!=' ')
    {
        mp1[s]++;
        s.clear();
    }
    for(auto c:s2)
    {
        if(c==' ')
        {
            mp2[s]++;
            s.clear();
            continue;
        }
        s+=c;
    }
    if(s.back()!=' ')
    {
        mp2[s]++;
        s.clear();
    }
    for(auto pair:mp1)
    {
        if(pair.second==1 and !mp2.count(pair.first)) ans.push_back(pair.first);
    }
    for(auto pair:mp2)
    {
        if(pair.second==1 and !mp1.count(pair.first)) ans.push_back(pair.first);
    }
    return ans;
}
