vector<string> wordSubsets(vector<string> &w1, vector<string> &w2)
{
    vector<string> ans;
    vector<int> map(26,0);
    for(string s:w2)
    {
        vector<int> temp(26,0);
        for(char c:s)
        {
            int idx = (int) c-'a';
            temp[idx]++;
        }
        for(int i=0;i<26;i++)
        {
            map[i] = max(map[i],temp[i]);
        }
    }

    for(string s:w1)
    {
        vector<int> temp(26,0);
        for(char c:s)
        {
            int idx = (int) c-'a';
            if(temp[idx]<map[idx]) temp[idx]++;
        }
        if(map==temp)
        {
            ans.push_back(s);
        }
    }
    return ans;
}
