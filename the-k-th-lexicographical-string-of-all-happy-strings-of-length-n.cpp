int found = 0;
string helper(int n, string temp,int k)
{
    if(temp.size()==n)
    {
        found++;
        if(found==k) return temp;
        return "";
    }
    
    for(int i=0;i<3;i++)
    {
        temp.push_back(97+i);
        int idx = temp.size()-1;
        if(idx>0 and temp[idx]==temp[idx-1]) 
        {
            temp.pop_back();
            continue;
        }
        string res = helper(n,temp,k);
        if(res.size()) return res;
        temp.pop_back();
    }
    return "";
}

string getHappyString(int n, int k) {
    string temp = "";
    return helper(n,temp,k);
}
