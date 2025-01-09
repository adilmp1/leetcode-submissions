int maximumSetSize(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int a_b=0, b_a=0, common = 0;

    unordered_set<int> s1(a.begin(),a.end());
    unordered_set<int> s2(b.begin(),b.end());

    unordered_set<int> merged;

    for(auto i:s1) merged.insert(i);
    for(auto i:s2) merged.insert(i);

    common = s1.size()+s2.size()-merged.size();

    a_b = s1.size()-common;
    b_a = s2.size()-common;

    int ans = 0;

    ans+=min(n/2,a_b);
    ans+=min(n/2,b_a);
    ans+=common;

    return min(ans,n);
}
