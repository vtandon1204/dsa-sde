#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0) // 0-element found in matrix
            {
                matrix[i][0] = 0; // mark its corresponding row as 0
                if (j != 0)
                {
                    matrix[0][j] = 0; // mark its corresponding column as 0 (if its not the first column)
                }
                else
                {
                    col0 = 0; // else mark the first column as 0
                }
            }
        }
    }

    for (int i = 1; i < m; i++)
    { // start from (1,1) till (m-1,n-1)
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] != 0)
            { // if any element is non-zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {                     // check if its corresponding row or column is amrked as 0
                    matrix[i][j] = 0; // then mark that element as 0
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    { // if first element of row[] is 0
        for (int j = 0; j < n; j++)
        { // then mark all the columns in first row as 0
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    { // if first column of col[] (col0) is 0
        for (int i = 0; i < m; i++)
        { // then mark all the rows in first column as 0
            matrix[i][0] = 0;
        }
    }
}
