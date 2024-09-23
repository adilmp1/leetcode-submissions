int convertToNumber(vector<vector<int>> &a)
{
    int sum=0;
    for(auto i:a)
    {
        int num=0;
        for(auto j:i)
        {
            num*=2;
            if(j==1) num++;
        }
        sum+=num;
    }
    return sum;
}
int matrixScore(vector<vector<int>> &a)
{

    int m = a.size();
    int n = a[0].size();

    for(int i=0;i<m;i++)
    {
        if(a[i][0]==0)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=!a[i][j];
            }
        }
    }

    for(int j=1;j<n;j++)
    {
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            cnt+=a[i][j];
        }
        if(cnt<m-cnt)
        {
            for(int i=0;i<m;i++)
            {
                a[i][j]=!a[i][j];
            }
        }
    }
    return convertToNumber(a);
}
