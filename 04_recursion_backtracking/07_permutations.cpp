#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;

    if (nums.size() == 1)
    {
        ans.push_back({nums[0]});
        return ans;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[i];
        vector<int> remaining;
        for (int j = 0; j < nums.size(); j++)
        {
            if (j != i)
            {
                remaining.push_back(nums[j]);
            }
        }

        vector<vector<int>> perms = permute(remaining);

        for (vector<int> p : perms)
        {
            p.insert(p.begin(), n);
            ans.push_back(p);
        }
    }

    return ans;
}