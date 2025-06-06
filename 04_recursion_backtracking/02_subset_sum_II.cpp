#include <bits/stdc++.h>
using namespace std;

void func(int i, vector<int> &temp, vector<int> &nums,
          vector<vector<int>> &ans)
{
    ans.push_back(temp); // Store the subset

    for (int j = i; j < nums.size(); ++j)
    {
        // Skip duplicates
        if (j > i && nums[j] == nums[j - 1])
            continue;

        temp.push_back(nums[j]);
        func(j + 1, temp, nums, ans);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    func(0, temp, nums, ans);
    return ans;
}