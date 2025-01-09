bool helper(string s,string pref)
{
    for(int i=0;i<pref.size();i++)
    {
        if(s[i]!=pref[i])
        {
            return false;
        }
    }
    return true;
}

int prefixCount(vector<string> &a, string pref)
{
    int ans=0;
    for(string i:a)
    {
        ans+=helper(i,pref);
    }
    return ans;
}
