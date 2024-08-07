int ladderLength(string beginWord, string endWord, vector<string> &a)
{
    unordered_map<string, int> mp;
    for (string i : a)
        mp[i] = 1;
    queue<pair<string, int>> q;
    mp.erase(beginWord);
    q.push({beginWord, 1});
    int level = 0;
    while (!q.empty())
    {
        string s = q.front().first;
        level = q.front().second;
        q.pop();
        if (s == endWord)
        {
            return level;
        }
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            for (int j = 0; j < 26; j++)
            {
                s[i] = (char)97 + j;
                if (mp.find(s) != mp.end())
                {
                    q.push({s, level + 1});
                    mp.erase(s);
                }
            }
            s[i] = c;
        }
    }
    return 0;
}
