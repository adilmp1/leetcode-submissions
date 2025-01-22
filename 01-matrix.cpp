bool isValid(int x, int y, int m, int n) {
    return (x >= 0 && y >= 0 && x < m && y < n);
}

vector<vector<int>> updateMatrix(vector<vector<int>> &a) {
    int m = a.size();
    int n = a[0].size();
    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                ans[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    vector<int> X = {0, 0, 1, -1};
    vector<int> Y = {1, -1, 0, 0};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int row = x + X[i];
            int col = y + Y[i];
            if (isValid(row, col, m, n) && ans[row][col] > ans[x][y] + 1) {
                ans[row][col] = ans[x][y] + 1;
                q.push({row, col});
            }
        }
    }
    return ans;
}
