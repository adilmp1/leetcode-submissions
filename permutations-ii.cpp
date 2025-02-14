set<vector<int>> s;
void helper(vector<int>& a,vector<int> temp,vector<bool> selected)
{
    if(temp.size()==a.size())
    {
        s.insert(temp);
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(!selected[i])
        {
            temp.push_back(a[i]);
            selected[i]=true;
            helper(a,temp,selected);
            selected[i]=false;
            temp.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& a) 
{
    int n = a.size();
    vector<int> temp;
    vector<bool> selected(n,false);
    helper(a,temp,selected);
    vector<vector<int>> ans;
    for(auto v:s) ans.push_back(v);
    return ans;
}
