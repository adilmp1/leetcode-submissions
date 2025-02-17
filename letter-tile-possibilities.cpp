
unordered_map<string,int> mp;
int ans=0;
void helper(string s,string temp,vector<bool>& selected)
{
    if(!temp.empty() and mp.find(temp)==mp.end())
    {
        mp[temp]=1;
        ans++;
    }
    for(int i=0;i<s.size();i++)
    {
        if(!selected[i])
        {
            temp+=s[i];
            selected[i]=true;
            helper(s,temp,selected);
            selected[i]=false;
            temp.pop_back();
        }
    }
}

int numTilePossibilities(string s) 
{
    vector<bool> selected(s.size(),false);
    helper(s,"",selected);
    return ans;        
}
