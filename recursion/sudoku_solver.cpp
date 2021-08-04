// https://leetcode.com/problems/sudoku-solver/

class Solution
{
public:
    bool canPlace(vector<vector<char>> &board, int i, int j, int n, char no)
    {
        // check for columns and rows
        for (int k = 0; k < n; k++)
        {
            if (board[k][j] == no || board[i][k] == no)
                return false;
        }

        // check for subgrid (starting coordinates of grid)
        int sx = (i / 3) * 3;
        int sy = (j / 3) * 3;
        for (int x = sx; x < sx + 3; x++)
        {
            for (int y = sy; y < sy + 3; y++)
            {
                if (board[x][y] == no)
                    return false;
            }
        }

        // pass all the constraints
        return true;
    }
    bool solveSudokuProblem(vector<vector<char>> &board, int i, int j, int n)
    {
        // base case
        if (i == n)
            return true;

        // end of row
        if (j == n)
            return solveSudokuProblem(board, i + 1, 0, n);
        
        // skip already filled cell
        if (board[i][j] != '.')
            return solveSudokuProblem(board, i, j + 1, n);

        // place all from '1' to '9'
        for (int no = 1; no <= n; no++)
        {
            char num = char(no-1+'1'); // char '1' - '9'
            if (canPlace(board, i, j, n, num))
            {
                board[i][j] = num;
                bool solveSubProblem = solveSudokuProblem(board, i, j + 1, n);
                if (solveSubProblem == true)
                    return true;
            }
        }

        // if no option works
        board[i][j] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solveSudokuProblem(board, 0, 0, 9);
    }
};