static bool comparator(string &a,string &b)
{
    return a+b>b+a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> a;
    for(auto i:nums) a.push_back(to_string(i));
    sort(a.begin(),a.end(),comparator);
    string ans="";
    for(auto i:a) ans+=i;
    int idx=0;
    while(ans[idx]=='0' and idx!=ans.size()-1) idx++;
    ans = ans.substr(idx);
    return ans;
}
