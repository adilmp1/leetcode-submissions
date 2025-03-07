int findIdx(vector<int>& a,int target)
{
    auto it = find(a.begin(),a.end(),target);
    if(it==a.end()) return -1;
    return distance(a.begin(),it);
}

int findTheWinner(int n, int k) 
{
    vector<int> a;
    for(int i=1;i<=n;i++) a.push_back(i);
    int start = 1;
    while(a.size()>1)
    {
        int idx = findIdx(a,start);
        int remove_idx = (idx+k-1)%a.size();
        a.erase(a.begin()+remove_idx);
        int next = a[remove_idx%a.size()];
        start = next;
    }
    return a[0];
}
