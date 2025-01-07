bool isSubstring(string a, string b)
{
    int m = a.size();
    int n = b.size();

    for (int i = 0; i < n; i++)
    {
        if (b[i] == a[0])
        {
            if (b.substr(i, m) == a)
                return true;
        }
    }
    return false;
}

vector<string> stringMatching(vector<string> &words)
{
    set<string> s;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words.size(); j++)
        {
            if (i!=j and isSubstring(words[i], words[j]))
            {
                s.insert(words[i]);
            }
        }
    }
    vector<string> ans;
    for (string i:s)
        ans.push_back(i);
    return ans;
}
