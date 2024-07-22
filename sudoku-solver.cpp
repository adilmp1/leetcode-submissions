bool isValid(int row,int col,char val,vector<vector<char>> &board)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==val) return false;
        if(board[i][col]==val) return false;
        int rowIndex = 3*(row/3)+i/3;
        int colIndex = 3*(col/3)+i%3;
        if(board[rowIndex][colIndex]==val) return false;
    }
    return true;
}
bool solveSudokuHelper(vector<vector<char>> &board)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.')
            {
                for(int val=1;val<=9;val++)
                {
                    if(isValid(i,j,val+'0',board))
                    {
                        board[i][j]=val+'0';
                        if(solveSudokuHelper(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    solveSudokuHelper(board);
    for(auto i:board)
    {
        for(int j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
