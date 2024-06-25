vector<vector<string>> ans;
bool isValid(vector<string> &board,int row,int col)
{
    int n = board.size();
    for(int i=0;i<col;i++) if(board[row][i]=='Q') return false;
    for(int i=0;i<row;i++) if(board[i][col]=='Q') return false;
    for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--) if(board[i][j]=='Q') return false;
    for(int i=row-1,j=col+1;i>=0 and j<board.size();i--,j++) if(board[i][j]=='Q') return false;
    return true;
}
void backtrack(int n, vector<string> &board, int row)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (isValid(board, row, col))
        {
            board[row][col] = 'Q';
            backtrack(n, board, row + 1);
            board[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    ans.clear();
    vector<string> board(n,string(n, '.'));
    backtrack(n, board, 0);
    return ans;
}
