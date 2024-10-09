int minAddToMakeValid(string str)
{
    int cnt = 0;
    stack<char> s;
    for (auto c : str)
    {
        if(c=='(')
        {
            s.push(c);
        }
        else
        {
            if(!s.empty())
            {
                s.pop();
            }
            else
            {
                cnt++;
            }
        }
    }
    return cnt+s.size();
}
