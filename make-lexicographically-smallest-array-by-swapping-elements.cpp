// My code 

vector<int> lexicographicallySmallestArray(vector<int>& a, int limit)
{
    int n = a.size();
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.push_back(INT_MAX);
    unordered_map<int,vector<int>> mp;
    unordered_map<int,int> index;
    vector<int> temp;
    int idx=0;
    for(int i=0;i<=n;i++)
    {
        if(temp.empty())
        {
            temp.push_back(b[i]);
            index[b[i]]=idx;
        }
        else
        {
            int diff = abs(b[i]-b[i-1]);
            if(diff<=limit)
            {
                temp.push_back(b[i]);
                index[b[i]]=idx;
            }
            else
            {
                sort(temp.begin(),temp.end(),greater<int>());
                mp[idx] = temp;
                idx++;
                temp.clear();
                i--;
            }
        }
    }
    for(auto pair:mp)
    {
        cout<<pair.first<<" => ";
        for(auto i:pair.second) cout<<i<<" ";
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        a[i] = mp[index[a[i]]].back();
        mp[index[a[i]]].pop_back();
    }
    return a;
}
