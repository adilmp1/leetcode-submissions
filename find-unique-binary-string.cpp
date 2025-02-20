unordered_map<string,int> mp;
string helper(int n,string temp)
{
    if(temp.size()==n)
    {
        if(mp.find(temp)==mp.end()) return temp;
        return "";
    }
    for(int i=0;i<=1;i++)
    {
        temp.push_back(i+'0');
        string ans = helper(n,temp);
        if(ans.size()) return ans;
        temp.pop_back();
    }
    return "";
}
string findDifferentBinaryString(vector<string>& a) 
{
    for(string i:a) mp[i]=1; 
    int n = a.size();
    string temp="";
    return helper(n,temp);
}
