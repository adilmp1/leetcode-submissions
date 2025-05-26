int lengthLongestPath(string input)
{
    stack<int> s;
    int ans = 0;

    istringstream ss(input);
    string line;
    while (getline(ss, line))
    {
        int depth = 0;

        while (line[depth] == '\t')
            depth++;

        while (!s.empty() and s.size() > depth)
            s.pop();

        string name = line.substr(depth);

        int length = (s.empty() ? 0 : 1 + s.top()) + name.size();

        if (name.find('.') != string::npos)
            ans = max(ans, length);
        else
            s.push(length);
    }
    return ans;
}
