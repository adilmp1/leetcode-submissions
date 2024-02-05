vector<vector<string>> ans;
bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}
void helper(int idx, vector<string> &tempVector, string &temp, string s, int n)
{
    if (idx == n)
    {
        if (tempVector.size() != 0)
        {
            string news = "";
            for (auto i : tempVector)
                news += i;
            if (news == s)
                ans.push_back(tempVector);
        }
        if (tempVector.size() != 0)
            tempVector.pop_back();
        return;
    }
    temp.push_back(s[idx]);
    if (isPalindrome(temp))
    {
        tempVector.push_back(temp);
        string copy_temp = temp;
        temp.clear();
        helper(idx + 1, tempVector, temp, s, n);
        temp = copy_temp;
        helper(idx + 1, tempVector, temp, s, n);
    }
    else
        helper(idx + 1, tempVector, temp, s, n);
}
vector<vector<string>> partition(string s)
{
    int n = s.size();
    vector<string> tempVector;
    string temp = "";
    helper(0, tempVector, temp, s, n);
    return ans;
}
