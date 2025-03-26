#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    if (numRows == 1)
        return {{1}};
    if (numRows == 2)
        return {{1}, {1, 1}};

    vector<vector<int>> ans(numRows);
    // first two rows of ans
    ans[0] = {1};
    ans[1] = {1, 1};

    for (int i = 2; i < numRows; i++) // starting from row 3 (index 2)
    {
        vector<int> temp(i + 1); // genrating the next row of ans in temp of size(i+1)
        temp[0] = 1;
        temp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            temp[j] = ans[i - 1][j] + ans[i - 1][j - 1];
        }
        ans[i] = temp;
    }
    return ans;
}