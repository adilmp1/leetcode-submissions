int ans=0;
void helper(string s,int pos,unordered_set<string>& mp)
{
    if(pos>=s.size())
    {
        int val = mp.size();
        ans = max(ans,val);
        return;
    }
    string temp="";
    for(int i=pos;i<s.size();i++)
    {
        temp.push_back(s[i]);

        if(!mp.count(temp))
        {
            mp.insert(temp);
            helper(s,i+1,mp);
            mp.erase(temp);
        }
    }
}

int maxUniqueSplit(string s)
{
    unordered_set<string> mp;
    helper(s,0,mp);
    return ans;
}
