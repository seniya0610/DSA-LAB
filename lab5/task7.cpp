// N Queens Problem using backtracking
#include <iostream>
using namespace std;

const int N = 4;

bool isSafe(int board[N][N], int row, int col)
{

    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

bool NQueenSolver(int board[N][N], int row)
{
    if (row >= N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 1;
            if (NQueenSolver(board, row + 1))
            {
                return true;
            }

            board[row][i] = 0; // backtracking
        }
    }
    return false;
}

void display(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int board[N][N] = {0};

    if (NQueenSolver(board, 0))
    {
        display(board);
    }
    else
    {
        cout << "No solution exists" << endl;
    }
}
