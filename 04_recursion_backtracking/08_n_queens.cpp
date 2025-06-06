#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n)
{
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0) // checking upper diagonal
    {
        if (board[row][col] == 'Q') // if Q is present in the upper diagonal then return false
        {
            return false;
        }
        row--;
        col--;
    }

    row = duprow;
    col = dupcol;

    while (col >= 0) // checking left side
    {
        if (board[row][col] == 'Q') // if Q is present in the left side then return false
        {
            return false;
        }
        col--;
    }

    row = duprow;
    col = dupcol;

    while (row < n && col >= 0) // checking lower diagonal
    {
        if (board[row][col] == 'Q') // if Q is present in the lower diagonal then return false
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
    if (col == n)
    {
        ans.push_back(board); // all cols are processed and now push the board in the ans and return
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n)) // if Q can be filled in that [row][col] then fill and call the recursive function for next column
        {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.'; // after returning from the recursive function make the cell empty again
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s; // making a board of (n) rows with a string of size (n)
    }

    solve(0, board, ans, n);
    return ans;
}