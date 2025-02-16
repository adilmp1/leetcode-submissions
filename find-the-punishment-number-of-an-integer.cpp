bool helper(string s,int target,int idx)
{
    if(idx>=s.size() and target==0) return true;
    
    string curr="";
    for(int i=idx;i<s.size();i++)
    {
        curr+=s[i];
        if(helper(s,target-stoi(curr),i+1)) return true;
    }
    return false;
}

bool isPossible(int n) {
    int square = n*n;
    string s = to_string(square);
    return helper(s,n,0);
}


int punishmentNumber(int n) 
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(isPossible(i)) ans+=i*i;
    }
    return ans;
}
