int numSubmat(vector<vector<int>> &a)
{
    int m = a.size(), n = a[0].size();
    vector<int> histogram(n,0);
    // height, gap, prev ans 
    int ans=0;
    for(int i=0;i<m;i++)
    {
        stack<vector<int>> s;
        s.push({-1,-1,0});
        for(int j=0;j<n;j++)
        {
            if(a[i][j]) histogram[j]++;
            else histogram[j]=0;
            while(s.top()[0]>=histogram[j]) s.pop();
            int gap = j-s.top()[1];
            int val = gap*histogram[j]+s.top()[2];
            s.push({histogram[j],j,val});
            ans+=val;
        }
    }
    return ans;
}
