unordered_set<string> vis;
string ans = "";
void helper(string s,int a,int b)
{
    if(vis.find(s)!=vis.end()) return;
    if(ans=="") ans = s;
    else ans = min(ans,s);
    vis.insert(s);
    string temp = s;
    for(int i=1;i<temp.size();i+=2)
    {
        int c = (temp[i]-'0'+a)%10;
        temp[i] = c+'0';
    }
    helper(temp,a,b);
    int rotation_count = b%s.size();
    int idx=0;
    for(int i=s.size()-rotation_count;i<s.size();i++) temp[idx++] = s[i];
    for(int i=0;i<s.size()-rotation_count;i++) temp[idx++]=s[i];
    helper(temp,a,b);
}

string findLexSmallestString(string s, int a, int b) {
    helper(s,a,b);
    return ans;
}
