vector<string> ans;
void helper(int n,string temp)
{
    if(temp.size()==n)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<=1;i++)
    {
        if(!temp.empty() and i==0 and temp.back()=='0') continue;
        temp.push_back(i+'0');
        helper(n,temp);
        temp.pop_back();
    }
}
vector<string> validStrings(int n) 
{
    string temp="";
    helper(n,temp);
    return ans;
}
