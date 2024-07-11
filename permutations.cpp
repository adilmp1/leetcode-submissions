    vector<vector<int>> ans;
    void permuteHelper(vector<int>& a,int idx,vector<int> temp,vector<bool> selected)
    {
        if(temp.size()==a.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<selected.size();i++)
        {
            if(!selected[i])
            {
                selected[i]=true;
                temp.push_back(a[i]);
                permuteHelper(a,idx,temp,selected);
                selected[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& a) 
    {
        int n=a.size();
        vector<int> temp;
        vector<bool> selected(n,false);
        permuteHelper(a,0,temp,selected);
        return ans;
    }
