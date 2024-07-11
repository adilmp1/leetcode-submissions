string multiply(string num1, string num2)
{
    int start = 1;
    string ans = "";
    for (int i = num2.size() - 1; i >= 0; i--)
    {
        string part;
        int extra = 0;
        for (int j = num1.size() - 1; j >= 0; j--)
        {
            int v1 = num2[i] - '0';
            int v2 = num1[j] - '0';
            int product = extra + (v1 * v2);
            extra = product / 10;
            product %= 10;
            part += product + '0';
        }
        if(extra) part.push_back(extra+'0');
        if (!ans.size())
        {
            ans = part;
        }
        else
        {
            int l1 = start;
            int l2 = 0;
            extra = 0;
            while (l1 < ans.size() and l2 < part.size())
            {
                int v1 = ans[l1] - '0';
                int v2 = part[l2] - '0';
                int sum = v1 + v2 + extra;
                extra = sum / 10;
                sum %= 10;
                ans[l1] = sum + '0';
                l1++;
                l2++;
            }
            while (l2 < part.size())
            {
                int v2 = part[l2] - '0';
                int sum = v2 + extra;
                extra = sum / 10;
                sum %= 10;
                ans.push_back(sum + '0');
                l2++;
            }
            if(extra) ans.push_back(extra+'0');
            start++;
        }
    }
    while(ans.size()!=1 and ans.back()=='0') ans.pop_back(); 
    reverse(ans.begin(),ans.end());
    return ans;
}
