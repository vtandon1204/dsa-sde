#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &maze, int n)
{
    if (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1)
    { // check if the cell is within bounds and is not blocked by 0
        return true;
    }
    return false;
}

void solve(int row, int col, vector<vector<int>> maze, int n, string &path, vector<string> &ans)
{
    // base case
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(path);
        return;
    }

    string dir = "DLRU";       // Down, Left, Right, Up
    int dr[4] = {1, 0, 0, -1}; // Down, Left, Right, Up
    int dc[4] = {0, -1, 1, 0}; // Down, Left, Right, Up

    maze[row][col] = 0; // mark as visited
    for (int i = 0; i < 4; i++)
    {
        int newRow = row + dr[i]; // calculate new row
        int newCol = col + dc[i]; // calculate new column
        // check if the new cell is safe to move
        if (isSafe(newRow, newCol, maze, n))
        {
            path.push_back(dir[i]); // add direction to path
            // recursive call to explore further
            solve(newRow, newCol, maze, n, path, ans);
            // backtrack - remove the direction from path
            path.pop_back();
        }
    }
    maze[row][col] = 1; // backtrack - unmark the cell
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    vector<string> ans;
    string path = "";

    if (!maze[0][0] && !maze[n - 1][n - 1]) // if start or end is not blocked
        solve(0, 0, maze, n, path, ans);
    return ans;
}