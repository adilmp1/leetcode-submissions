string helper(string s,string& temp,int id,vector<bool>& selected,int idx)
{
    if(temp.size()==s.size()+1)
    {
        return temp;
    }
    if(idx==-1)
    {
        for(int i=id;i<=9;i++)
        {
            if(!selected[i])
            {
                temp.push_back(i+'0');
                selected[i]=true;
                string ans = helper(s,temp,i,selected,idx+1);
                if(ans.size()==s.size()+1) return ans;
                selected[i]=false;
                temp.pop_back();
            }
        }
    }
    else if(s[idx]=='I')
    {
        for(int i=id+1;i<=9;i++)
        {
            if(!selected[i])
            {
                temp.push_back(i+'0');
                selected[i]=true;
                string ans = helper(s,temp,i,selected,idx+1);
                if(ans.size()==s.size()+1) return ans;
                selected[i]=false;
                temp.pop_back();
            }
        }
        
    }
    else if(s[idx]=='D')
    {
        for(int i=1;i<id;i++)
        {
            if(!selected[i])
            {
                temp.push_back(i+'0');
                selected[i]=true;
                string ans = helper(s,temp,i,selected,idx+1);
                if(ans.size()==s.size()+1) return ans;
                selected[i]=false;
                temp.pop_back();
            }
        }
    }

    return "";
}

string smallestNumber(string s)
{
    int n = s.size();
    vector<bool> selected(9,false);
    string temp="";
    return helper(s,temp,1,selected,-1);
}
