vector<string> ans;
int temp[2] = {0, 0};
string cars = "()";
void helper(string &s, int n)
{
    if (s.size() == 2 * n)
    {
        ans.push_back(s);
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        if (temp[i] < n)
        {
            if (i == 0 or (i == 1 and temp[i] != temp[i - 1]))
            {
                s.push_back(cars[i]);
                temp[i]++;
                helper(s, n);
                s.pop_back();
                temp[i]--;
            }
        }
    }
}
vector<string> generateParenthesis(int n)
{
    string s = "";
    helper(s, n);
    return ans;
}
