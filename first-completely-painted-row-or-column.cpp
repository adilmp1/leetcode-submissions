int firstCompleteIndex(vector<int> &a, vector<vector<int>> &mat)
{
    unordered_map<int,pair<int,int>> mp;
    int m = mat.size(), n = mat[0].size();
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            mp[mat[i][j]]={i,j};
        }
    }
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;

    for(int i=0;i<a.size();i++)
    {
        auto& pair = mp[a[i]];
        int x = pair.first;
        int y = pair.second;
        mp1[x]++;
        mp2[y]++;
        if(mp1[x]==n or mp2[y]==m) return i;
    }
    return -1;
}
