vector<vector<int>> generateMatrix(int n) 
{
    vector<vector<int>> a(n,vector<int>(n,0));
    int num = 1;
    int top=0,bottom=n-1,left=0,right=n-1;

    while(top<=bottom and left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            a[top][i]=num++;
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            a[i][right]=num++;
        }
        right--;
        for(int i=right;i>=left;i--)
        {
            a[bottom][i]=num++;
        }
        bottom--;
        for(int i=bottom;i>=top;i--)
        {
            a[i][left]=num++;
        }
        left++;
    }
    return a;
}
