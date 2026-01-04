int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<int> rowMax(n);
    vector<int> colMax(n);
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        int rowMaxi = 0;
        int colMaxi = 0;
        for (int j = 0; j < n; j++)
        {
            rowMaxi = max(rowMaxi, grid[i][j]);
            colMaxi = max(colMaxi, grid[j][i]);
        }
        rowMax[i] = rowMaxi;
        colMax[i] = colMaxi;
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans+=min(rowMax[i],colMax[j])-grid[i][j];
    return ans;
}
