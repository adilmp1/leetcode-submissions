int numberOfPairs(vector<vector<int>> &a)
{   
    sort(a.begin(),a.end(),[](const vector<int>& b,const vector<int>& c){
        if(b[0]==c[0]) return (b[1]<c[1]);
        return b[0]>c[0];
    });

    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        int x = a[i][0];
        int y = a[i][1];
        int max_y = INT_MAX;
        for(int j=i+1;j<a.size();j++)
        {
            vector<int>& curr = a[j];
            if(curr[1]>=y and curr[1]<max_y)
            {
                max_y = curr[1];
                ans++;
            }
        }
    }
    return ans;
}
