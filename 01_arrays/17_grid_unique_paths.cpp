#include <bits/stdc++.h>
using namespace std;

int cntPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    // ************************* Memoization *************************************

    // Base Case: if we reach the destination cell (n-1, m-1)
    if (i == (n - 1) && j == (m - 1))
        return 1;
    // Base Case: if we go out of bounds of the grid
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = cntPaths(i + 1, j, n, m, dp) + cntPaths(i, j + 1, n, m, dp);
    // check for down and right
}
int uniquePaths(int m, int n)
{
    // vector<vector<int>> dp(m, vector<int>(n, -1));
    // return cntPaths(0,0,m,n,dp);

    // ************************* Tabulation *************************************

    // vector<vector<int>> dp(m, vector<int>(n, 0));

    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         // Base Case: start position
    //         if (i == 0 && j == 0)
    //             dp[i][j] = 1;
    //         else {
    //             int up = (i > 0) ? dp[i - 1][j] : 0;
    //             int left = (j > 0) ? dp[i][j - 1] : 0;
    //             dp[i][j] = up + left;
    //         }
    //     }
    // }

    // return dp[m - 1][n - 1];

    // ************************* Combinatorics *************************************

    int N = m + n - 2;
    int R = n - 1;
    double res = 1;
    for (int i = 1; i <= R; i++)
    {
        res = res * (N - R + i) / i; // C(N, R) = N! / (R! * (N - R)!)
        // we have to choose (n-1) correct steps from (m+n-2) steps
    }
    return (int)res;
}