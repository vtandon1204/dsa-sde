#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int i = 0; i < n - 1; i++) // transpose matrix
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++) // reversing the columns to get clockwise rotation
    {
        reverse(mat[i].begin(), mat[i].end());
    }

    // for anticlockwise rotation, reverse the rows instead of columns
    // for (int i = 0; i < n; i++)
    // {
    //     reverse(mat.begin(), mat.end());
    // }
}