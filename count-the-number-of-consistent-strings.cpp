unordered_set<char> s;
bool isAllowed(string str)
{
    for(auto c:str) if(s.find(c)==s.end()) return false;
    return true;
}
int countConsistentStrings(string allowed, vector<string> &a)
{
    int count=0;
    for(auto c:allowed) s.insert(c);
    for(auto str:a) count+=isAllowed(str);
    return count;
}
