int maxDiff(int num)
{
    string s = to_string(num);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(char i='0';i<='9';i++)
    {
        for(char j='0';j<='9';j++)
        {
            string temp = s;
            for(int k=0;k<s.size();k++) if(temp[k]==i) temp[k]=j;
            int no = stoi(temp);
            maxi = max(maxi,no);
            if(temp[0]!='0' and no) mini = min(mini,no);
        }
    }
    return maxi-mini;
}
