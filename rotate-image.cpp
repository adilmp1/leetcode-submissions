#define n a.size()
void rotate(vector<vector<int>> &a)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0;i<n;i++) reverse(a[i].begin(),a[i].end());
}
